#include <iostream>
#include <queue>
#include "Tree.h"

using namespace std;

// Helper function to print branches of the binary tree
void Tree::showTrunks(Trunk* p)
{   
    if (p == nullptr) {
        return;
    }

    showTrunks(p->prev);
    cout << p->str;
}

void Tree::printTree(Struct* root, Trunk* prev, bool isLeft) {

    if (root == nullptr) {
        return;
    }

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    Tree::printTree(root->right, trunk, true);

    if (!prev) {
        trunk->str = "---";
    }
    else if (isLeft)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << " " << root->value << endl;

    if (prev) {
        prev->str = prev_str;
    }
    trunk->str = "   |";

    Tree::printTree(root->left, trunk, false);
}

void Tree::show() {
    printTree(head, nullptr, false);
};

Struct* Tree::insert(Struct* node, Struct* parent, int val) {
	if (!node) {
		Struct* new_data = new Struct();
		new_data->value = val;
        new_data->parent = parent;
		return new_data;
	}

    if (node->value == val) {
        cout << "\n\nElement (" << val << ") is already exist!\n\n";
        return node;
    }

	if (node->value > val) {
		node->left = insert(node->left, node, val);
	}
	else {
		node->right = insert(node->right, node, val);
	}

	return balance(node, parent);
}

void Tree::add(int val) {
    head = insert(head, nullptr, val);
}

int Tree::getHeight(Struct* node) {
    return node ? node->height: 0;
}

int Tree::bfactor(Struct* node) {
    return getHeight(node->right) - getHeight(node->left);
}

void Tree::fixHeight(Struct* node) {
    int hl = getHeight(node->left);
    int hr = getHeight(node->right);

    node->height = (hl > hr ? hl : hr) + 1;
}

Struct* Tree::getHead() {
	return head;
}

Struct* Tree::rotateRight(Struct* node, Struct* parent) {
    Struct* q = node->left;
    Struct* qr = q->right;

    q->right = node; node->parent = q;
    node->left = qr;
    if (qr)
        qr->parent = node;
    q->parent = parent;

    fixHeight(node);
    fixHeight(q);

    return q;
}

Struct* Tree::rotateLeft(Struct* node, Struct* parent) {
    Struct* q = node->right;
    Struct* ql = q->left;

    q->left = node; node->parent = q;
    node->right = ql;
    if (ql)
        ql->parent = node;
    q->parent = parent;

    fixHeight(node);
    fixHeight(q);

    return q;
}

Struct* Tree::balance(Struct* node, Struct* parent) {
    fixHeight(node);

    if (bfactor(node) == 2) {
        if (bfactor(node->right) < 0) {
            node->right = rotateRight(node->right, node);
        }
        return rotateLeft(node, parent);
    }

    if (bfactor(node) == -2) {
        if (bfactor(node->left) > 0) {
            node->left = rotateLeft(node->left, node);
        }
        return rotateRight(node, parent);
    }

    return node;
}

Struct* Tree::findmin(Struct* node) {
    return (node->left ? findmin(node->left) : node);
}

Struct* Tree::removemin(Struct* node, Struct* parent) {
    if (node->left == nullptr) {
        return node->right;
    }
    node->left = removemin(node->left, node);
    return balance(node, parent);
}

Struct* Tree::del(Struct* node, Struct* parent, int val) {
    if (!node) {
        cout << "\n\nElement \"" << val << "\" was not found!\n";
        return node;
    }

    if (val < node->value) {
        node->left = del(node->left, node, val);
    }
    else if (val > node->value) {
        node->right = del(node->right, node, val);
    }
    else {
        Struct* l = node->left;
        Struct* r = node->right;
        delete node;

        if (!r) return l;

        Struct* min = findmin(r);
        min->right = removemin(r, min);
        min->left = l;

        cout << "\n\nElement \"" << val << "\" was succesfully deleted!\n\n";
        return balance(min, parent);
    }
    return balance(node, parent);
}

Struct* Tree::del(Struct* node, Struct* parent) {
    Struct* l = node->left;
    Struct* r = node->right;
    delete node;

    if (!r) return l;

    Struct* min = findmin(r);
    min->right = removemin(r, min);
    min->left = l;

    return balance(min, parent);
}

void Tree::remove(int value) {
    head = del(head, head->parent, value);
}

Struct* Tree::get(Struct* node, int val, int step) {

    if (node->left == nullptr && node->right == nullptr && node->value != val) {
        cout << "\n\nElement \"" << val << "\" was not found!\n";
        return nullptr;
    }
    else if (node->value == val) {
        cout << "\n\nElement \"" << val << "\" was found in "<< step <<" steps!\n";
        if (node->parent)
            cout << "Parent of element - \"" << node->parent->value << "\"\n";
        else
            cout << "Parent of element - \"nullptr\"\n";
        return node;
    }
    else if (node->value < val) {
        node = get(node->right, val, step + 1);
    }
    else if (node->value > val) {
        node = get(node->left, val, step + 1);
    }
}

Struct* Tree::find(int val) {
    return get(head, val, 0);
}

void Tree::bfs_func() {
    queue<Struct**> q;
    bool parity = true;
    int i = 0;

    q.push(&head);

    if (!head)
        return;

    while (!q.empty()) {
        Struct** cur = q.front(); q.pop();

        if (cur) {
            Struct* tmp = *cur;
            if (parity && (tmp->left != nullptr || tmp->right != nullptr)) {
                *cur = del(*cur, tmp->parent);

                cout << "\nIteration: " << ++i << "\n\n";
                show();
            }

            parity = (parity ? false : true);
        }

        Struct* tmp = *cur;
        if (tmp) {
            if (tmp->left)
                q.push(&tmp->left);
            if (tmp->right)
                q.push(&tmp->right);
        }

    }
}

void Tree::func() {
    while (head->height > 1) {
        bfs_func();
    }
};

void Tree::bfs() {
    queue<Struct*> q;

    q.push(head);

    if (!head)
        return;

    while (!q.empty()) {
        Struct* cur = q.front(); q.pop();

        if (cur) {
            cout << "Element: " << cur->value << endl;
        }

        if (cur->left)
            q.push(cur->left);
        if (cur->right)
            q.push(cur->right);
    }
}