// Converted version of instructor's code
#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* lchild;
    int data;
    struct Node* rchild;
    int height;
}*root = NULL;

struct AVL {
    struct Node* root;
};

int NodeHeight(struct Node* p) {
    int hl;
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int BalanceFactor(struct Node* p) {
    int hl;
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl - hr;
}

struct Node* LLRotation(struct Node* p) {
    struct Node* pl = p->lchild;
    struct Node* plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    // Update height
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    // Update root
    if (root == p) {
        root = pl;
    }
    return pl;
}

struct Node* RRRotation(struct Node* p) {
    struct Node* pr = p->rchild;
    struct Node* prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    // Update height
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    // Update root
    if (root == p) {
        root = pr;
    }
    return pr;
}

struct Node* LRRotation(struct Node* p) {
    struct Node* pl = p->lchild;
    struct Node* plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    // Update height
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    // Update root
    if (p == root) {
        root = plr;
    }
    return plr;
}

struct Node* RLRotation(struct Node* p) {
    struct Node* pr = p->rchild;
    struct Node* prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    // Update height
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    // Update root
    if (root == p) {
        root = prl;
    }
    return prl;
}

struct Node* InPre(struct Node* p) {
    while (p && p->rchild != NULL) {
        p = p->rchild;
    }
    return p;
}

struct Node* InSucc(struct Node* p) {
    while (p && p->lchild != NULL) {
        p = p->lchild;
    }
    return p;
}

struct Node* rInsert(struct Node* p, int key) {
    struct Node* t;
    if (p == NULL) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = NULL;
        t->rchild = NULL;
        t->height = 1; // Starting height from 1 onwards instead of 0
        return t;
    }

    if (key < p->data) {
        p->lchild = rInsert(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = rInsert(p->rchild, key);
    }

    // Update height
    p->height = NodeHeight(p);

    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {
        return LLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1) {
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1) {
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1) {
        return RLRotation(p);
    }

    return p;
}

void Inorder(struct Node* p) {
    if (p) {
        Inorder(p->lchild);
        printf("%d, ", p->data);
        Inorder(p->rchild);
    }
}

struct Node* Delete(struct Node* p, int key) {
    if (p == NULL) {
        return NULL;
    }

    if (p->lchild == NULL && p->rchild == NULL && p->data == key) {
        if (p == root) {
            root = NULL;
        }
        free(p);
        return NULL;
    }

    if (key < p->data) {
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = Delete(p->rchild, key);
    } else {
        struct Node* q;
        if (NodeHeight(p->lchild) > NodeHeight(p->rchild)) {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }

    // Update height
    p->height = NodeHeight(p);

    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {  // L1 Rotation
        return LLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1) {  // L-1 Rotation
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1) {  // R-1 Rotation
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1) {  // R1 Rotation
        return RLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0) {  // L0 Rotation
        return LLRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0) {  // R0 Rotation
        return RRRotation(p);
    }

    return p;
}

int main() {
    struct AVL tree;
    tree.root = NULL;

    int A[] = {10,20,30,40,5};
    int n = sizeof(A) / sizeof(A[0]);

    for (int i = 0; i < n; i++) {
        tree.root = rInsert(tree.root, A[i]);
    }

    Inorder(tree.root);
    printf("\n");

    tree.root = Delete(tree.root, 5);

    Inorder(tree.root);
    printf("\n");

    return 0;
}
