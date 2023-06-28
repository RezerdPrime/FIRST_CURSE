#include <iostream>
#include <rd.cpp> // я рандомайзер уже заливал
using namespace std;

// #1 // ======================================================================================= //

struct Node {
	int val;
	Node* next;
};

void push(Node*& st, int dat) {

	Node* el = new Node;
	el->val = dat;
	el->next = st;
	st = el;
}

int pop(Node*& st) {

	int value = st->val;
	Node* temp = st;
	st = st->next;
	delete temp;

	return value;
}

int peek(Node* st) { return st->val; }

Node** graph;
const int vertex = 1;

void add(Node*& list, int data) {

	if (!list) { list = new Node; list->val = data; list->next = 0; return; }

	Node* temp = list;
	while (temp->next)temp = temp->next;
	Node* elem = new Node;
	elem->val = data;
	elem->next = NULL;
	temp->next = elem;
}

void del(Node*& l, int key) {

	if (l->val == key) { Node* tmp = l; l = l->next; delete tmp; }
	else {
		Node* tmp = l;
		while (tmp) {
			if (tmp->next)

				if (tmp->next->val == key) {
					Node* tmp2 = tmp->next;
					tmp->next = tmp->next->next;
					delete tmp2;
				}
			tmp = tmp->next;
		}
	}
}

int is_Euler(Node** gr, int num) {

	int count;
	for (int i = 0; i < num; i++) {

		count = 0;
		Node* tmp = gr[i];

		while (tmp) {
			count++; // подсчёт степени
			tmp = tmp->next;
		}
		if (count % 2 == 1) return 0; // степень нечетная
	}
	return 1; // все степени четные
}

void path(Node** gr) {

	Node* S = NULL;// Стек для пройденных вершин
	int v = vertex;
	int u;

	push(S, v); //сохраняем ее в стек
	while (S) {
		v = peek(S);
		if (!gr[v]) { // если нет инцидентных ребер
			v = pop(S); cout << v + 1 << "   ";
		}

		else {
			u = gr[v]->val; push(S, u);  // проходим в следующую вершину
			del(gr[v], u); del(gr[u], v); // удаляем пройденное ребро
		}
	}
}

void t1() {
	cout << "Set the vertex count:\n"; int n; cin >> n;
	int cur;

	graph = new Node * [n];
	for (int i = 0; i < n; i++) graph[i] = NULL;
	for (int i = 0; i < n; i++)

		for (int j = 0; j < n; j++) {

			cin >> cur;

			if (cur) add(graph[i], j);
		}

	cout << "\n\nResult: ";

	if (is_Euler(graph, n)) path(graph);
	else cout << "No man.";

	cout << endl;
}

/*
5
0 1 1 1 1
1 0 1 1 1
1 1 0 1 1
1 1 1 0 1
1 1 1 1 0

5
0 0 0 0 1
1 0 0 0 0
0 0 0 1 0
0 0 1 0 1
1 0 0 0 0

8
0 1 1 1 0 0 0 0
1 0 1 0 0 1 0 1
1 1 0 1 1 0 0 1
1 0 1 0 1 0 0 0
0 0 1 1 0 0 1 1
0 1 0 0 0 0 1 1
0 0 0 0 1 1 0 1
0 1 1 0 1 1 1 0

https://graphonline.ru/ */


// #2 // ======================================================================================= //

#include <iostream>
using namespace std;
int n;
#define INF 2147483647

int min_dist(int dist[], int visited[]) {
	int min = INF, min_index;
	for (int v = 0; v < n; v++) {
		if (visited[v] == 0 && dist[v] <= min) {
			min = dist[v];
			min_index = v;
		}
	}
	return min_index;
}

void sol(int dist[]) {
	cout << "Vertex: \t Dist:\n";
	for (int i = 0; i < n; i++)
		cout << i + 1 << "\t\t " << dist[i] << endl;
}

void D(int** graph, int start) {
	int* dist = new int[n]; // массив для хранения кратчайших расстояний от источника до всех вершин
	int* visited = new int[n];

	for (int i = 0; i < n; i++) {
		dist[i] = INF;
		visited[i] = 0;
	}
	dist[start] = 0;

	for (int count = 0; count < n - 1; count++) {
		int u = min_dist(dist, visited);
		visited[u] = 1;

		for (int v = 0; v < n; v++) {
			if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
		}
	}

	sol(dist); // Вывод кратчайших расстояний до всех вершин
}

void t2() {
	cout << "Set the vertex count:\n";
	cin >> n;
	int** graph = new int* [n];
	for (int i = 0; i < n; i++) graph[i] = new int[n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) graph[i][j] = graph[j][i] = (unsigned)RAND % 20;
			else graph[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << graph[i][j] << "\t ";
		} cout << "\n";
	} cout << '\n';

	D(graph, 0); // Вызов функции для начальной вершины 0
}


// #3 // ======================================================================================= //

#include <iostream>
#include <vector>
#include <queue>

vector<pair<int, int>> adj[50];
bool visited[50];
int dist[50];

void prim(int start) {
	memset(visited, false, sizeof visited);
	memset(dist, INF, sizeof dist);
	dist[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		if (visited[u]) {
			continue;
		}

		visited[u] = true;

		for (auto v : adj[u]) {
			if (!visited[v.first] && v.second < dist[v.first]) {
				dist[v.first] = v.second;
				pq.push(make_pair(dist[v.first], v.first));
			}
		}
	}
}

int t3() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cost;
			cin >> cost;
			adj[i].push_back(make_pair(j, cost));
			adj[j].push_back(make_pair(i, cost));
		}
	}

	prim(1);

	int ans = 0;
	int roads = 0;

	int B[50][50] = { 0 };

	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF) {
			cout << "-1" << endl;
			return 0;
		}

		ans += dist[i];
		roads++;

		int u = i, v = i + 1;
		if (v > n) {
			v = 1;
		}

		while (visited[v]) {
			v++;
			if (v > n) {
				v = 1;
			}
		}

		B[u][v] = B[v][u] = 1;
	}

	cout << "Rezults:" << endl;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << B[i][j] << " ";
		}
		cout << endl;
	}
}


// #4 // ======================================================================================= //

#include <vector>
#include <algorithm>

struct Road {
	int from;
	int to;
	int distance;
};

void t4() {
	cout << "Set the vertex and edges counts:\n";

	int N, K;
	cin >> N >> K; //cout << "a\n";
	vector<int> houses(N + 1);

	for (int i = 0; i <= N; i++) cin >> houses[i];
	//cout << "a\n";

	vector<Road> roads(K);
	for (int i = 0; i < K; i++) {
		cin >> roads[i].from >> roads[i].to >> roads[i].distance;
	}

	int min_tot_dist = INF;
	int meet_pt;

	for (int i = 0; i < N; i++) {
		int tot_dist = 0;

		for (int j = 0; j < N; j++) tot_dist += abs(houses[i] - houses[j]);

		if (tot_dist < min_tot_dist) {
			min_tot_dist = tot_dist;
			meet_pt = i + 1;
		}
	}

	for (int i = 0; i < K; i++) {
		int from = roads[i].from - 1;
		int to = roads[i].to - 1;
		int distance = roads[i].distance;
		int tot_dist = 0;

		for (int j = 0; j < N; j++) {
			tot_dist += min(abs(houses[j] - houses[from]) + distance + abs(houses[j] - houses[to]),
				abs(houses[j] - houses[to]) + distance + abs(houses[j] - houses[from]));
		}

		if (tot_dist < min_tot_dist) {
			min_tot_dist = tot_dist;
			meet_pt = min(houses[from], houses[to]) + distance / 2;
		}
	}
	cout << "Meeting point:" << meet_pt << endl;
}

int main() {
	t4();
}
