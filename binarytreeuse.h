template<typename T>
class binarytreenode{
public:
int data;
binarytreenode *left;
binarytreenode *right;

binarytreenode(T data){
    this->data=data;
    left=NULL;
    right=NULL;
}

};