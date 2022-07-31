#include <stdio.h>
#include <stdlib.h>
struct node
{
	struct node *lchild;
	int data;
	int height;
	struct node *rchild;

}*root=NULL;
int nodeheight(struct node*p){
	int hl,hr;
	hl=p && p->lchild?p->lchild->height:0;
	hr=p&&p->rchild?p->rchild->height:0;
	return hl>hr?hl+1:hr+1;
}
int balancefactor(struct node*p){
	int hl,hr;
	hl=p && p->lchild?p->lchild->height:0;
	hr=p&&p->rchild?p->rchild->height:0;
	return hl-hr;
}


struct node *ll(struct node *p){
	struct node*pl=p->lchild;
	struct node*plr=pl->rchild;
	pl->rchild=p;
	p->lchild=plr;
	p->height=nodeheight(p);
	pl->height=nodeheight(pl);
	if(root==p){
		root=pl;

	}return pl;

}
struct node *lr(struct node *p){
	struct node*pl=p->lchild;
	struct node*plr=pl->rchild;
	pl->rchild=plr->lchild;
	p->lchild=plr->rchild;
	plr->rchild=p;
	plr->lchild=pl;
	p->height=nodeheight(p);
	pl->height=nodeheight(pl);
	plr->height=nodeheight(plr);
	if(root==p){
		root=plr;

	}return plr;

}
struct node *rl(struct node *p){
	struct node*pr=p->rchild;
	struct node*prl=pr->lchild;
	pr->lchild=prl->rchild;
	p->rchild=prl->lchild;
	prl->rchild=pr;
	prl->lchild=p;
	p->height=nodeheight(p);
	pr->height=nodeheight(pr);
	prl->height=nodeheight(prl);
	if(root==p){
		root=prl;

	}return prl;

}
struct node *rr(struct node *p){
	struct node*pr=p->rchild;
	struct node*prl=pr->lchild;
	pr->lchild=p;
	p->rchild=prl;
	p->height=nodeheight(p);
	pr->height=nodeheight(pr);
	if(root==p){
		root=pr;

	}return pr;

}

struct node* insert(struct node*p,int key){
	struct node*t =NULL;
	if(p==NULL){
		t=(struct node*)malloc(sizeof(struct node));
		t->data=key;
		t->height=1;
		t->lchild=t->rchild=NULL;
		return t;
	}
	if(key<p->data){
		p->lchild=insert(p->lchild,key);
	}else if(key>p->data){
		p->rchild=insert(p->rchild,key);
	}
	p->height=nodeheight(p);
	if(balancefactor(p)==2 && balancefactor(p->lchild)==1){
		return ll(p);
	}
	else if(balancefactor(p)==2 && balancefactor(p->lchild)==-1){
		return lr(p);
	}
	else if(balancefactor(p)==-2 && balancefactor(p->rchild)==-1){
		return rr(p);
	}
	else if(balancefactor(p)==-2 && balancefactor(p->rchild)==1){
		return rl(p);
	}
	return p; 
}



int main(){
	struct node*p;
	root=insert(root,10);
	insert(root,20);
	insert(root,30);
	insert(root,25);
	insert(root,28);
	insert(root,27);
	insert(root,5);
	p=root;
	printf("%d",p->data);
}
