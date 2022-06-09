/*
Binary search tree Data Structure.

Methods:
  - insert
  - search
  - delete
  - traversals(preorder, inorder, postorder)
*/
#include <stdio.h>
#include <malloc.h>

struct Node {

       int data;
       struct Node *left;
       struct Node *right;
};

struct Node *insert(struct Node *node, int data) {

       if(node == NULL) {

          node = (struct Node*)malloc(sizeof(struct Node));
          node->data = data;
          node->left = NULL;
          node->right = NULL;

       } else {

         if(node->data > data)

           node->left = insert(node->left, data);

         else

           node->right = insert(node->right, data);
       }

       return node;
}

int search(struct Node *root, int data) {

    if(root != NULL) {

      if(root->data == data) {
        return 1;
      } else if(root->data > data) {
        return search(root->left, data);
      } else {
        return search(root->right, data);
      }

    }
    return 0;
}

void inorder(struct Node*root) {
     if(root->left) {
       inorder(root->left);
     }
     printf("%d ", root->data);
     if(root->right) {
       inorder(root->right);
     }
}

struct Node *mostlyRightMin(struct Node *node) {

        struct Node *curr = node;

        //look down to find leftmost leaf
        while(curr != NULL && curr->left!=NULL) {
          curr = curr->left;
        }
        return curr;
}

struct Node *delete( struct Node*root, int key ) {

      if( root == NULL ) return root;

      if( root->data > key )

        root->left = delete( root->left, key );

      else if( root->data < key )

        root->right = delete( root->right, key );

      else {

        if( root->left == NULL && root->right == NULL ) {

           free(root);

           root = NULL;

        } else if( root->left == NULL ) {

               struct Node *temp = root;
                      root = root->right;
                      free(temp);

        } else if( root-> right == NULL ) {

               struct Node *temp = root;
                     root = root->left;
                     free(temp);

        //we have both children: left and right
      } else if(root->left != NULL && root->right != NULL) {

               struct Node *p = mostlyRightMin(root->right);

               root->data = p->data;

               root->right = delete(root->right, p->data);
        }


      }

      return root;
}

int main(int argc, char const *argv[]) {

  struct Node *root = NULL;
  root = insert(root, 8);
         insert(root, 3);
         insert(root, 10);
         insert(root, 1);
         insert(root, 6);
         insert(root, 4);
         insert(root, 7);
         insert(root, 14);
         insert(root, 13);
  inorder(root);

  int key = 3;
  printf("\nDeleted Node = %d\n", key);
  delete(root, key);
  inorder(root);

  return 0;
}
