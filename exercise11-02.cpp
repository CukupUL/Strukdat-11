/*
Program		: exercise-02
Nama		: Nurul Ma'arif
NPM			: 140810180040
Deskripsi	: Binary Search Tree
Tanggal		: 15 Mei 2019
*/

#include<iostream>
using namespace std;

struct Simpul{
    int info;
    Simpul* left;
    Simpul* right;
};
typedef Simpul* pointer;
typedef pointer Tree;



void insertBST (Tree& Root, pointer pBaru){
    if(Root==NULL)
        Root=pBaru;  
    else if (pBaru->info < Root->info)
        insertBST(Root->left,pBaru);
    else if (pBaru->info > Root->info)
        insertBST(Root->right,pBaru);
    else
        cout<<"Sudah ada"<<endl;
    
}

void createSimpul(pointer& pBaru){
    pBaru=new Simpul;
    cin>>pBaru->info;
    pBaru->left=NULL;
    pBaru->right=NULL;
}

void preOrder (Tree Root) {
    if (Root != NULL){
        cout<< Root->info <<endl;
        preOrder(Root->left);
        preOrder(Root->right);
    }
}

void inOrder (Tree Root) {
    if (Root != NULL){
        inOrder(Root->left);
        cout<< Root->info <<endl;
        inOrder(Root->right);
    }
}

void postOrder (Tree Root) {
    if (Root != NULL){
        postOrder(Root->left);
        postOrder(Root->right);
        cout<< Root->info <<endl;
    }
}


int height(Tree Root){
    if (Root==NULL) return 0;
    else{
        int lHeight=height(Root->left);
        int rHeight=height(Root->right);

        if (lHeight>rHeight) return (lHeight+1);
        else return (rHeight+1);
    }
}


void givenLevel(Tree Root, int level){
    if (Root==NULL) 
        return;
    if (level==1) 
        cout << Root->info << " ";
    else if (level>1){
        givenLevel(Root->left,level-1);
        givenLevel(Root->right,level-1);
    }
}

void kedalaman(Tree Root){
    int h=height(Root);
    for (int i=1; i<=h; i++){
        cout << i-1 << ": " <<" [ ";
        givenLevel(Root,i);
        cout<< "]"<< endl;
    }
}

void levelOrder(Tree Root){
    int h=height(Root);
    for (int i=1; i<=h; i++){
        cout << i << ": " <<" [ ";
        givenLevel(Root,i);
        cout<< "]"<< endl;
    }
}

void Anak(Tree Root, pointer pBaru){
    pBaru= Root;
    if(pBaru!=NULL){
        cout<<"Parent Node = "<<pBaru->info<<endl;
        if(pBaru->left == NULL)
            cout<<"Left Child = NULL"<<endl;
        else
            cout<<"Left Child = "<<pBaru->left->info<<endl;
                     
        if(pBaru->right == NULL)
            cout<<"Right Child = NULL"<<endl;
        else
            cout<<"Right Child = "<<pBaru->right->info<<endl;
		
		cout<<endl;
        Anak(Root->left, pBaru);
        Anak(Root->right, pBaru);
    }
}

int main(){
	int pil, jum;
    Tree Root;
    pointer pBaru;
    char ans;
	Root=NULL;
	
   
    cout<<"Masukkan banyak data :"; cin>>jum;
    for (int i = 0; i < jum; i++){ 
		cout<<" input ke- "<<i + 1 << " : ";
		
        createSimpul(pBaru);
        insertBST(Root,pBaru); 
        
    }
    do{
        system("CLS");
    	cout<<"\t\tPILIH MENU DIBAWAH"<<endl;
    	cout<<"\t============================="<<endl;
    	cout<<"\t[1] Insert BST              |"<<endl;
    	cout<<"\t[2] Preorder                |"<<endl;
    	cout<<"\t[3] Inorder                 |"<<endl;
    	cout<<"\t[4] Postorder               |"<<endl;
    	cout<<"\t[5] Kedalaman               |"<<endl;
    	cout<<"\t[6] Level                   |"<<endl;
    	cout<<"\t[7] Anak                    |"<<endl;
    	cout<<"\t[8] Exit                    |"<<endl;
    	cout<<"\t============================="<<endl;
    	cout<<"Pilihan : ";cin>>pil;

    switch(pil){
    	case 1:
    		cout<<"\nInsert BST "<<endl;
        	createSimpul(pBaru);
        	insertBST(Root,pBaru);
        	
        case 2:
        	cout<<"\nPREORDER"<<endl;
        	preOrder(Root);
        	break;
        
        case 3:
        	cout<<"\nINORDER"<<endl;
        	inOrder(Root);
       	 	break;
        
        case 4:
        	cout<<"\nPOSTORDER"<<endl;
        	postOrder(Root);
        	break;

  		case 5:
        	cout<<"\nKEDALAMAN"<<endl;
        	kedalaman(Root);
        	break;
        	
        case 6:
        	cout<<"\nLEVEL"<<endl;
        	levelOrder(Root);
        	break;
        	
        case 7:
        	cout<<"ANAK"<<endl;
            Anak(Root, pBaru);
            break;
            
		case 8:
            cout<<"\nYesss BERES  "<<endl;
            return 0;
            break;
					
        default:
        	cout<<"Gesus beres Mang,Maaf Maaf aja ya !"<<endl;
        break;
    }
    cout<<"Kembali ke menu?(Y/N)"; cin>>ans;
}
while(ans=='y'|| ans=='Y');
}
