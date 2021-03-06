#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <iomanip>
#include <set>
#include <algorithm>

#include <chrono>

using namespace std::chrono;
using namespace std;


struct Edge {
  size_t to;
  long long w;
};

struct Node {
  std::vector<Edge> edges;

  void addEdge(Edge const &e) {
    edges.push_back(e);
  }
};

typedef std::vector<Node> graph_t;


vector<string> split(string const& s, string const& delimiter) {
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  string token;
  vector<string> res;

  while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back(token);
  }

  res.push_back(s.substr(pos_start));
  return res;
}

vector<string> split2(string const& s, string const& del1, string const& del2) {
  size_t pos_start = 0, pos_end, len1 = del1.length(), len2 = del2.length();
  size_t pos1 = string::npos, pos2 = string::npos;
  string token;
  vector<string> res;

  size_t len;

  while ((pos1 = s.find(del1, pos_start)) != string::npos || (pos2 = s.find(del2, pos_start)) != string::npos) {
    if (pos2 == string::npos || pos1 < pos2) {
      pos_end = pos1;
      len = len1;
    } else {
      pos_end = pos2;
      len = len2;
    }
    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + len;
    res.push_back(token);
    pos1 = string::npos;
    pos2 = string::npos;
  }

  res.push_back(s.substr(pos_start));
  return res;
}

uint32_t x = 538;
uint32_t my_rand() {
  x ^= x << 13;
  x ^= x >> 17;
  x ^= x << 5;
  return x;
}

vector<Node> parseTxtFile(string const& filename) {
  vector<Node> nodes;
  ifstream file(filename);
  string line;

  uint64_t cnt = 0;

  while (getline(file, line)) {
    if (line.find("# ") == 0) {
      // ignore
    } else {
      cnt++;
      if (cnt % 1000000 == 0) cout << "Reading.. " << cnt / 1000000 << endl;
      auto parts = split2(line, " ", "\t");
      auto from = stoi(parts[0]);
      auto to = stoul(parts[1]);
      auto w = my_rand() % 100;
      while (nodes.size() <= from || nodes.size() <= to) {
        nodes.emplace_back();
      }
      nodes[from].addEdge({to, w});
    }
  }
  file.close();
  return nodes;
}

vector<Node> parseGrFile(string const& filename) {
  vector<Node> nodes;
  ifstream file(filename);
  string line;

  uint64_t cnt = 0;

  while (getline(file, line)) {
    if (line.find("p sp ") == 0) {
      auto spl = split(line, " ");
      auto nds = vector<Node>(stoi(spl[2]));
      nodes.insert(nodes.end(), nds.begin(), nds.end());
    } else if (line.find("a ") == 0) {

      cnt++;
      if (cnt % 1000000 == 0) cout << "Reading.. " << cnt / 1000000 << endl;

      auto parts = split(line, " ");
      auto from = stoll(parts[1]) - 1;
      auto to = stoll(parts[2]) - 1;
      if (to == 264346)
        cout << "what the hell" << endl;
      auto w = stoll(parts[3]);
      nodes[from].addEdge({to, w});
    }
  }
  file.close();
  return nodes;
}

void writeGrFile(string const& filename, vector<Node> const& nodes) {
  ofstream out(filename);
  size_t cnt_edges = 0;
  for (auto n : nodes)
    cnt_edges += n.edges.size();
  out << "p sp " << nodes.size() << " " << cnt_edges << endl;
  for (size_t i = 0; i < nodes.size(); i++) {
    for (auto e : nodes[i].edges)
      out << "a " << i + 1 << " " << e.to + 1 << " " << e.w << "\n";
  }
  out.close();
}

void createBottleGraph(vector<Node>& nodes) {
  if (nodes.size() == 0)
    return;
  auto copy = nodes;
  std::queue<size_t> q;
  std::vector<size_t> res(nodes.size(), SIZE_MAX);
  q.push(0);
  res[0] = 0;
  while (!q.empty()) {
    auto id = q.front();
    q.pop();
    for (auto e : nodes[id].edges) {
      if (res[e.to] > res[id] + 1) {
        res[e.to] = res[id] + 1;
        q.push(e.to);
      }
    }
  }
  auto n = nodes.size();
  size_t ind = 0;
  size_t dist = 0;
  for (size_t i = 1; i < n; i++) {
    if (res[i] != SIZE_MAX && res[i] > dist) {
      dist = res[i];
      ind = i;
    }
  }

  cout << "The furthest node: " << ind << endl;
  cout << "Its distance: " << dist << endl;
  nodes[ind].addEdge({n, 100});
  for (size_t i = 1; i <= res[ind]; i++) {
    auto node = Node();
    node.addEdge({n + i, 100});
    nodes.push_back(node);
  }
  auto curSize = nodes.size();
  cout << "Size with bamboo: " << curSize << endl;
  for (size_t i = 0; i < n; i++) {
    nodes.push_back(copy[i]);
    for (auto& e : nodes.back().edges) {
      e.to += curSize;
    }
  }
  //nodes.push_back(Node()); // do we need back edges?
  std::cout << "Previous size: " << n << std::endl;
  std::cout << "New size: " << nodes.size() << std::endl;
  std::cout << "Destination: " << curSize + ind << std::endl;
}

int main(int argc, char* argv[]) {
  if (argc <= 2) {
    cerr << "Provide filename and result filename" << endl;
    return 0;
  }
  string in = argv[1];
  string out = argv[2];
  auto nodes = parseGrFile(in);
  createBottleGraph(nodes);
  writeGrFile(out, nodes);
}
