// Var 20

#include <iostream>
#include <stack>

using namespace std;

void show(int** map, int m, int n) {
	cout << "\n\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\n";
}

int main() {
	setlocale(LC_ALL, "rus");

	int m, n;
	cout << "Введите число вершин: ";
	cin >> m;
	
	int** imap = new int* [m];

	cout << "Введите число дуг: ";
	cin >> n;

	if (n == 0 || m == 0) {
		std::cout << "\n\nНе перезнакомить\n";
		return 0;
	}
	cout << "\nВведите матрицу инцидентности: " << endl;
	for (int i = 0; i < m; i++) {
		imap[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> imap[i][j];
		}
	}

	// Transforming to adjacency matrix

	int** map = new int*[m];

	for (int i = 0; i < m; i++) {
		map[i] = new int[m];
		for (int j = 0; j < m; j++) {
			map[i][j] = 0;
		}
	}

	for (int j = 0; j < n; j++) {
		int vertexcount = 0;
		int vertices[2];

		for (int i = 0; i < m; i++) {
			if (imap[i][j]) {
				vertices[vertexcount] = i;
				vertexcount++;
				if (vertexcount == 2) break;
			}
		}

		if (vertexcount == 2) {
			map[vertices[0]][vertices[1]] = 1;
			map[vertices[1]][vertices[0]] = 1;
		}
	}

	int* flagArray = new int[m];

	for (int i = 0; i < m; i++) {
		flagArray[i] = 0;
	}

	stack<int> st;

	st.push(0);
	flagArray[0] = 1;

	while (!st.empty()) {
		int vertex = st.top(); st.pop();

		for (int i = 0; i < m; i++) {
			if (map[vertex][i] && !flagArray[i]) {
				flagArray[i] = 1;
				st.push(i);
			}
		}
	}

	cout << "\n\nМатрица смежности:";
	show(map, m, m);

	cout << "Список связности:\n";
	for (int i = 0; i < m; i++) {
		cout << flagArray[i] << " ";
	}

	for (int i = 0; i < m; i++) {
		if (!flagArray[i]) {
			std::cout << "\n\nНе перезнакомить\n";
			return 0;
		}
	}

	std::cout << "\n\nМожно перезнакомить\n";
	return 0;
}

/*

1)

1 1 0 0
1 0 1 1
0 0 0 1
0 1 1 0

2)

1 1 0 0
1 0 1 0
0 0 0 0
0 1 1 0

3)

1 0 1 0 0
1 1 0 0 0
0 1 1 0 0
0 0 0 1 0
0 0 0 1 1
0 0 0 0 1

4)

1 0 1 0 0 0
1 1 0 0 0 0
0 1 1 0 0 1
0 0 0 1 0 1
0 0 0 1 1 0
0 0 0 0 1 0

*/