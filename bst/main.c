#include "bst.h"
#include <stdio.h>

int main(void) {
  BST bst;
  init(&bst);

  printf("=== insert ===\n");
  insert(&bst, 10);
  insert(&bst, 5);
  insert(&bst, 20);
  insert(&bst, 3);
  insert(&bst, 7);
  insert(&bst, 15);
  insert(&bst, 25);
  insert(&bst, 10); // duplicate

  printf("size: %zu\n\n", bst.size);

  //       10
  //      /  \
  //     5    20
  //    / \  /  \
  //   3   7 15  25

  printf("=== traversals ===\n");
  printf("inorder   (sorted): ");
  print(&bst, "inorder");
  printf("preorder  (root first): ");
  print(&bst, "preorder");
  printf("postorder (root last): ");
  print(&bst, "postorder");
  printf("invalid mode: ");
  print(&bst, "levelorder");
  printf("\n");

  printf("=== find ===\n");
  Node *found = find(&bst, 7);
  printf("find(7):  %s (data=%d)\n", found ? "found" : "not found",
         found ? found->data : -1);
  Node *missing = find(&bst, 99);
  printf("find(99): %s\n\n", missing ? "found" : "not found");

  printf("=== successor ===\n");
  Node *n5 = find(&bst, 5);
  Node *n25 = find(&bst, 25);
  Node *succ5 = successor(n5);
  Node *succ25 = successor(n25);
  printf("successor(5):  %d\n", succ5 ? succ5->data : -1); // expect 7
  printf("successor(25): %s\n\n",
         succ25 ? "found" : "NULL (no successor, max node)"); // expect NULL

  printf("=== delete leaf (3) ===\n");
  delete (&bst, 3);
  printf("inorder: ");
  print(&bst, "inorder");
  printf("size: %zu\n\n", bst.size);

  printf("=== delete one-child node (5) ===\n");
  delete (&bst, 5);
  printf("inorder: ");
  print(&bst, "inorder");
  printf("size: %zu\n\n", bst.size);

  printf("=== delete two-child node (20) ===\n");
  delete (&bst, 20);
  printf("inorder: ");
  print(&bst, "inorder");
  printf("size: %zu\n\n", bst.size);

  printf("=== delete non-existent (99) ===\n");
  bool removed = delete (&bst, 99);
  printf("delete(99): %s\n\n", removed ? "removed" : "not found");

  destroy(&bst);
  return 0;
}
