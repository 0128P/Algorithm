#include <stdio.h>
#include <stdlib.h>

typedef char data;
typedef struct _Node {
  char key;
  struct _Node *left;
  struct _Node *right;
}Node;

/*
* 찾기
* 자기 자신보다 작으면 왼쪽 자식, 크면 오른쪽 자식
* 찾는 값이랑 같으면 값 반환
* NULL이 될 때 까지 반복하다가 NULL 반환
*/
Node *searchBST(Node *root, char x) {
  Node *p = root;
  while(p != NULL) {
    if(p->key == x) {
      return p;
    } else if(p->key < x) {
      p = p->right;
    } else {
      p = p->left;
    }
  }
  return NULL;
}

Node *insertBST(Node *root, char x) {
  Node *p = root;
  Node *parent = NULL;
  while(p!=NULL) {
    parent = p;
    if(p->key == x) {
      printf("같은 키가 있습니다.");
      return p;
    } else if(p->key < x) {
      p = p->right;
    } else {
      p = p->left;
    }
  }
  //새 Node 할당
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->key = x;
  newNode->left = newNode->right = NULL;

  //parent의 자식으로 새 Node 붙이기
  if(parent != NULL) {
    if(parent->key < newNode->key) {
      parent->right = newNode;
    } else {
      parent->left = newNode;
    }
  }
  return newNode;
}

/*
* 삭제하는 3가지 방법
* 차수가 0인경우, 1인경우, 2인경우 
* 0인경우 = 해당 Node만 free시키고 Node로 향하는 parent pointer만 NULL값으로 교체 
*/
Node *deleteBST(Node *root, char x) {
  Node *p = root;
  Node *parent = NULL;
  //찾는 Node가 없거나 key를 찾은것도 아닌 동안은 계속 반복 
  while((p!=NULL) && (p->key!=x)) {
    parent = p;
    if(p->key < x) {
      p = p->right;
    } else {
      p = p->left;
    }
  }
  if(p == NULL) {
    printf("찾는 노드가 없습니다.\n");
    return root;
  }
  //차수가 0
  //왼쪽도 NULL, 오른쪽도 NULL이면 차수가 0
  if(p->left==NULL && p->right==NULL) {
    //현재 노드가 rootNode인데 차수가 0인 경우와
    //root가 아닌데 차수가 0인 경우로 나눠야 함
    if(parent==NULL) {
      root = NULL;
    } else {
      if(parent->left == p) {
        parent->left = NULL;
      } else {
        parent->right = NULL;
      }
    }
  } else if(p->left == NULL || p->right == NULL) { //차수가 1
    //왼쪽이랑 오른쪽 중 값이 있는 걸 child에 넣음 
    Node *child = (p->left != NULL) ? p->left : p->right;
    if(parent == NULL) {
      root = child;
    } else {
      if(parent->left == p) {
        parent->left = child;
      } else {
        parent->right = child;
      }
    }
  } else { //차수가 2
    Node *succ_parent = p;
    Node *succ = p->right;
    while(succ->left != NULL) {
      succ_parent = succ;
      succ = succ->left;
    }
    p->key = succ->key;
    if(succ_parent->left == succ) {
      succ_parent->left = succ->right;
    } else {
      succ_parent->right = succ->right;
    }
    p = succ;
  }
  free(p);
  return root;
}

void Inorder(Node *root) {
  if(root == NULL) {
    return;
  }
  Inorder(root->left);
  printf("%c",root->key);
  Inorder(root->right);
}

int main() {
  Node *root = insertBST(NULL,'D');
  insertBST(root, 'I');
  insertBST(root, 'F');
  insertBST(root, 'A');
  insertBST(root, 'G');
  insertBST(root, 'C');
  Inorder(root);
  printf("\n");
  return 0;
}
