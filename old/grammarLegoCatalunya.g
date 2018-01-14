#header
<<
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// struct to store information about tokens
typedef struct {
  string kind;
  string text;
} Attrib;

// function to fill token information (predeclaration)
void zzcr_attr(Attrib *attr, int type, char *text);

// fields for AST nodes
#define AST_FIELDS string kind; string text;
#include "ast.h"

// macro to create a new AST node (and function predeclaration)
#define zzcr_ast(as,attr,ttype,textt) as=createASTnode(attr,ttype,textt)
AST* createASTnode(Attrib* attr,int ttype, char *textt);
>>

<<
#include <cstdlib>
#include <cmath>

//global structures
AST *root;


// function to fill token information
void zzcr_attr(Attrib *attr, int type, char *text) {
/*  if (type == ID) {
    attr->kind = "id";
    attr->text = text;
  }
  else {*/
    attr->kind = text;
    attr->text = "";
//  }
}

// function to create a new AST node
AST* createASTnode(Attrib* attr, int type, char* text) {
  AST* as = new AST;
  as->kind = attr->kind; 
  as->text = attr->text;
  as->right = NULL; 
  as->down = NULL;
  return as;
}


/// create a new "list" AST node with one element
AST* createASTlist(AST *child) {
 AST *as=new AST;
 as->kind="list";
 as->right=NULL;
 as->down=child;
 return as;
}

/// get nth child of a tree. Count starts at 0.
/// if no such child, returns NULL
AST* child(AST *a,int n) {
  AST *c=a->down;
  for (int i=0; c!=NULL && i<n; i++) c=c->right;
  return c;
}

int childCount(AST *a, int count) {
  if (a == NULL){
    return count;
  }else{
    count++;
    return childCount(a->right, count);
  }
}

/// print AST, recursively, with indentation
void ASTPrintIndent(AST *a,string s)
{
  if (a==NULL) return;

  cout<<a->kind;
  if (a->text!="") cout<<"("<<a->text<<")";
  cout<<endl;

  AST *i = a->down;
  while (i!=NULL && i->right!=NULL) {
    cout<<s+"  \\__";
    ASTPrintIndent(i,s+"  |"+string(i->kind.size()+i->text.size(),' '));
    i=i->right;
  }
  
  if (i!=NULL) {
      cout<<s+"  \\__";
      ASTPrintIndent(i,s+"   "+string(i->kind.size()+i->text.size(),' '));
      i=i->right;
  }
}

/// print AST 
void ASTPrint(AST *a)
{
  while (a!=NULL) {
    cout<<" ";
    ASTPrintIndent(a,"");
    a=a->right;
  }
}

typedef struct{
  int x, y;
  int w, h;
} tblock;

typedef struct{
  int n, m;
  vector < vector<int> > height;
  map< string, tblock > blocks;
} Graella;

Graella g;

tblock *findAndModify(map< string, tblock > *blocks, string target){
  map<string, tblock>::iterator it;
  for (it = blocks->begin(); it != blocks->end(); it++){
    if(it->first == target){
      return &it->second;
    }
  }
}

bool exists(map< string, tblock > blocks, string target){
  map<string, tblock>::iterator it;
  for (it = blocks.begin(); it != blocks.end(); it++){
    if(it->first == target){
      return true;
    }
  }
  return false;
}

void handlePushPop(AST *a){
  AST *c;
  string newBlock = child(a,0)->kind;
  string blockOn = child(child(a,1),1)->kind;
  string t = child(child(a,1),1)->kind;
  tblock *tBlock;

  if(blockOn == "POP"){
    blockOn = child(child(child(a,1),1),1)->kind;
  }

  tblock *newBloc;
  tblock *blocOn = findAndModify(&g.blocks, blockOn);

  if (exists(g.blocks, newBlock) == false){

    int w = atoi(child(child(child(a,1),0),0)->kind.c_str());
    int h = atoi(child(child(child(a,1),1),1)->kind.c_str());

    if(blocOn->w < w || blocOn->h < h){
      cout << "The block cannot be pushed."<< endl; 
    }else{
      newBloc->w = w;
      newBloc->h = h;
    }
  }else{

    tBlock = findAndModify(&g.blocks, t);
    int starty = tBlock->x;
    int endy = tBlock->w; 
    int startx = tBlock->y;
    int endx = tBlock->h; 

    for (int i = startx-1; i < startx+endx-1; i++) {
        for (int j = starty-1; j < starty+endy-1; j++) {
            g.height[i][j]--;
        }
    }
  }

  int startOnx = blocOn->x;
  int endOnw = blocOn->w; 
  int startOny = blocOn->y;
  int endOnh = blocOn->h; 
  
  int samey,county,samex,countx,posx,posy;

    for (int i = startOnx-1; i < startOnx+endOnw-1; i++) {
      for (int j = startOny-1; j < startOny+endOnh-1; j++) {
          if(g.height[i][j] != samey){
            samey = g.height[i][j];
            county=0;
            posy = j;
          } else {
            county++;
          }
      }
      samey = g.height[i][0];
      posy = 0;
      county = 0;
  }
  for(int j = startOny-1; j < startOny+endOnh-1; j++) {
     for (int i = startOnx-1; i < startOnx+endOnw-1; i++) {
          if(g.height[i][j] != samey){
            samex = g.height[i][j];
            posx = i;
          } else {
            countx++;
          }
      }
      samex = g.height[0][j];
      posx = 0;
      countx = 0;
  }
      cout << newBlock << "countx: " << countx << " posx: "<< posx<< "county: " << county << " posy: "<< posy <<endl;

  if(county>=startOny+endOnh && countx >= startOnx+endOnw){
    cout << newBlock << "can go up";
    newBloc->x = posx;
    newBloc->y = posy;
  }

  for (int i = 0; i < g.height.size(); i++){
    for (int j = 0; j < g.height[i].size(); j++){
        cout << g.height[i][j];
    }
    cout << endl;
  }
  cout <<endl;

/*
  starty = t->x;
  endy = t->w; 
  startx = t->y;
  endx = t->h; 

  for (int i = startx-1; i < startx+endx-1; i++) {
      for (int j = starty-1; j < starty+endy-1; j++) {
          g.height[i][j]++;
      }
    }

  for (int i = 0; i < g.height->size(); i++){
    for (int j = 0; j < g.height[i].size(); j++){
        cout << g.height[i][j];
    }
    cout << endl;
  }
  cout <<endl;
  */
}

int realHeight(AST *a, string target){
  tblock *t = findAndModify(&g.blocks, target);
  int max;

  int starty = t->x;
  int endy = t->w; 
  int startx = t->y;
  int endx = t->h; 

  max =0;
  for (int i = startx-1; i < startx+endx-1; i++) {
      for (int j = starty-1; j < starty+endy-1; j++) {
          if(g.height[i][j] > max){
            max = g.height[i][j];
          }
      }
  }
  return max;
}

int evaluate(AST *a){
    if(a->kind == "FITS"){

    }else{
      string sintax = a->kind;
      int num = atoi(child(a,1)->kind.c_str());
      string check = child(child(a,0),0)->kind;
      int height = realHeight(a, check);
      if(sintax == ">"){
        if(height > num){
          return 1;
        }else{
          return 0;
        }
      }else{
        if(height < num){
          return 1;
        }else{
          return 0;
        }
      }

    }
}

bool evaluateWhile(AST *a){
  /*string numCond = child(a,0)->kind;
  int sum; 

  if(numCond == "AND"){
    int count = childCount(child(child(a,0),0),0);
    for(int i = 0; i < count; i++){
      sum += evaluate(child(child(a,0),i));
    }
    if (sum == count){
      return true;
    }else{
      return false;
    }
  }else{
    if(evaluate(child(a,0)) == 1){
      return true;
    }else{
      return false;
    }
  }
*/
}


string functionDeclared;

void checkOps(AST *a){

  if (a == NULL){
    return;
  }else if(a->kind == "="){
    if (child(a,1)->kind == "PLACE"){
      tblock t;

      t.x = atoi(child(child(child(a,1),1),0)->kind.c_str());
      t.y = atoi(child(child(child(a,1),1),1)->kind.c_str());
      t.w = atoi(child(child(child(a,1),0),0)->kind.c_str());
      t.h = atoi(child(child(child(a,1),0),1)->kind.c_str());

      string name = child(a,0)->kind;
      int starty = t.x;
      int endy = t.w; 
      int startx = t.y;
      int endx = t.h; 

      for (int i = startx-1; i < startx+endx-1; i++) {
        for (int j = starty-1; j < starty+endy-1; j++) {
            g.height[i][j]++;
        }
      }

      g.blocks.insert(std::pair< string, tblock>(name, t));
      
    }else if((child(a,1)->kind == "PUSH")){
      //handlePushPop(a);
    }

  }else if (a->kind == "MOVE"){
    string name = child(a,0)->kind;
    string dir = child(a,1)->kind;
    int distance = atoi(child(a,2)->kind.c_str());

    tblock *t = findAndModify(&g.blocks, name);
    int starty = t->x;
    int endy = t->w; 
    int startx = t->y;
    int endx = t->h; 

    if(dir == "NORTH"){
      if(t->y - distance - 1< 0){
        cout << "Move operation " << dir <<" " << distance << " cannot be performed." << endl;
        return;
      }else{
        for (int i = startx-1; i < startx+endx-1; i++) {
          for (int j = starty-1; j < starty+endy-1; j++) {
            g.height[i][j]--;
          }
        }
        t->y = t->y - distance;
      }
    }else if(dir == "SOUTH"){
      if(t->y + distance - 1 > g.n){
        cout << "Move operation " << dir <<" " << distance << " cannot be performed." << endl;
        return;
      }else{
        for (int i = startx-1; i < startx+endx-1; i++) {
          for (int j = starty-1; j < starty+endy-1; j++) {
            g.height[i][j]--;
          }
        }
        t->y = t->y + distance;
      }
    }else if (dir == "EAST"){
      if(t->x + distance -1 > g.m){
        cout << "Move operation " << dir <<" " << distance << " cannot be performed." << endl;
        return;
      }else{
        for (int i = startx-1; i < startx+endx-1; i++) {
          for (int j = starty-1; j < starty+endy-1; j++) {
            g.height[i][j]--;
          }
        }
        t->x = t->x + distance;
      }
    }else if (dir == "WEST"){
      if(t->x - distance -1 < 0){
        cout << "Move operation " << dir <<" " << distance << " cannot be performed." << endl;
        return;
      }else{
        for (int i = startx-1; i < startx+endx-1; i++) {
          for (int j = starty-1; j < starty+endy-1; j++) {
            g.height[i][j]--;
          }
        }
        t->x = t->x - distance;
      }
    }

    starty = t->x;
    endy = t->w; 
    startx = t->y;
    endx = t->h; 

    for (int i = startx-1; i < startx+endx-1; i++) {
      for (int j = starty-1; j < starty+endy-1; j++) {
          g.height[i][j]++;
      }
    }
      
 }else if(a->kind == "HEIGHT"){
    string blockName = child(a,0)->kind;
    cout << "The height of the block " << blockName << " is: " <<realHeight(a, blockName)<< endl;
 }else if(a->kind == "WHILE"){

    int count = childCount(child(child(a,1),0),0);
    while(evaluateWhile(a)){
      for(int i = 0; i < count; i++){
        checkOps(child(child(a,1),i));
      }
    }


 }else{
    functionDeclared = a->kind;
 }

}

void checkDefs(AST *a){

  if(child(a,0)->kind == functionDeclared){

    int count = childCount(child(child(a,1),0),0);
    for(int i = 0; i < count; i++){
      checkOps(child(child(a,1),i));
    }

  }else{
    cout << "The function was not declared, please declare this function." << endl;
  }
  
}

void executeListInstructions(AST *a){
  int count;
  if(child(a,0)->kind != "Grid"){
    cout << "Please create a grid first" << endl;
    return;
  }else{
    g.n = atoi(child(child(a,0),0)->kind.c_str());
    g.m = atoi(child(child(a,0),1)->kind.c_str());
    int n = g.n;
    int m = g.m;
    g.height.resize(n);

    for (int i = 0; i < n; i++){
        g.height[i].resize(m);
    }

  }

  if(child(a,1)->kind == "list"){
    count = childCount(child(child(a,1),0),0);
    for(int i = 0; i < count; i++){
      checkOps(child(child(a,1),i));
    }
  }

  if(child(a,2)->kind == "list"){
    count = childCount(child(child(a,2),0),0);
    for(int i = 0; i < count; i++){
      checkDefs(child(child(a,2),i));
    }
  }
  

}

int main() {
	root = NULL;
  ANTLR(lego(&root), stdin);
  ASTPrint(root);
  executeListInstructions(root);
}

>>

#lexclass START

#token SPACE "[\ \n]" << zzskip();>>
#token EQUALS "="
#token GREATER ">"
#token LOWER "<"
#token AND "AND"
#token MOVE "MOVE"
#token PUSH "PUSH"
#token POP "POP"
#token PLACE "PLACE"
#token AT "AT"
#token PAROP "\("
#token PARCLO "\)"
#token COMMA ","
#token BRACOP "\["
#token BRACCLO "\]"
#token GRID "Grid"
#token FITS "FITS"
#token HEIGHT "HEIGHT"
#token CARD "(NORTH | SOUTH | EAST | WEST)"
#token WHILE "WHILE"
#token DEF "DEF"
#token ENDEF "ENDEF"
#token NUM "[0-9]+"
#token BLOCK "[A-Z][0-9]+"
#token FUNCT "[a-zA-Z]+[0-9]*"

lego: grid ops defs <<#0=createASTlist(_sibling);>>;

grid: (GRID^ NUM NUM) ;
ops: (assign | move | functi | height | fits | whil)* <<#0=createASTlist(_sibling);>>;
defs: (definition)* <<#0=createASTlist(_sibling);>>;

definition: DEF^ FUNCT ops ENDEF!;
functi: FUNCT;

assign: (BLOCK EQUALS^ (place | pushpop));
place: (PLACE^ coo AT! coo);

pushpop: (BLOCK|(PAROP! nums PARCLO!)) PUSH^ pushpoprule;
pushpoprule: BLOCK (POP^ BLOCK | );

move: (MOVE^ BLOCK CARD NUM) ;

height: (HEIGHT^ PAROP! BLOCK PARCLO!);

fits: (FITS^ PAROP! BLOCK COMMA! nums COMMA! NUM PARCLO!);

nums: (NUM COMMA! NUM) <<#0=createASTlist(_sibling);>>;

whil: WHILE^ cond inside;

inside: BRACOP! ops BRACCLO!;

pushblock: BLOCK (POP^ BLOCK | );

coo: (PAROP! NUM COMMA! NUM PARCLO!) <<#0=createASTlist(_sibling);>>;

cond: PAROP! whilecond PARCLO!;
whilecond: condition (AND^ condition)*;
condition: (height  (GREATER^ | LOWER^)  NUM | fits);