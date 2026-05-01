//#include<iostream>
//
//#include<vector>
//#include<cmath>
//#include<iomanip>
//#include<algorithm>
//#include<list>
//#include<string>
//#include<map>
//
//using namespace std;
//struct Point
//{
//    double x;
//    double y;
//};
//struct HeapItem
//{
//    double distance;
//    int groupP; 
//    int groupQ;
//    bool remov; 
//};
//class MinHeap
//{
//private:
//    vector<HeapItem> heapArray;
//    map<pair<int, int>, int> indexMap;
//
//    int parent(int i) { return (i - 1) / 2; }
//    int left(int i) { return (2 * i + 1); }
//    int right(int i) { return (2 * i + 2); }
//
//    void update(int i) {
//        indexMap[{heapArray[i].groupP, heapArray[i].groupQ}] = i;
//    }
//
//    void heapifyup(int i)
//    {
//        while (i != 0 && heapArray[parent(i)].distance > heapArray[i].distance) {
//            swap(heapArray[i], heapArray[parent(i)]);
//            update(i);
//            update(parent(i));
//            i = parent(i);
//        }
//    }
//
//    void heapifydown(int i)
//    {
//        int l = left(i);
//        int r = right(i);
//        int smallest = i;
//
//        if (l < heapArray.size() && heapArray[l].distance < heapArray[smallest].distance)
//        {
//            smallest = l;
//        }
//        if (r < heapArray.size() && heapArray[r].distance < heapArray[smallest].distance)
//        {
//            smallest = r;
//        }
//
//        if (smallest!= i)
//       {
//            swap(heapArray[i], heapArray[smallest]);
//            update(i);
//            update(smallest);
//            heapifydown(smallest);
//        }
//    }
//
//public:
//    map<pair<int, int>, int>& getIndexMap()
//    {
//        return indexMap;
//    }
//    vector<HeapItem>& getHeapArray() { return heapArray; }
//
//    int size() const
//    {
//        return heapArray.size(); 
//    }
//    bool isEmpty() const 
//    {
//        return heapArray.empty();
//    }
//
//    void buildheap(const vector<HeapItem>& initialItems)
//    {
//        heapArray = initialItems;
//        for (int i = 0; i < heapArray.size(); i++)
//        {
//            update(i);
//        }
//        for (int i = (heapArray.size() / 2) - 1; i >= 0; i--)
//        {
//            heapifydown(i);
//        }
//    }
//
//    HeapItem extractmin()
//    {
//        if (isEmpty()) {
//            return HeapItem{ -1.0, -1, -1, true };
//        }
//
//        while (!isEmpty())
//        {
//            HeapItem root = heapArray[0];
//
//            swap(heapArray[0], heapArray.back());
//            update(0);
//
//            heapArray.pop_back();
//
//            if (!isEmpty())
//            {
//                heapifydown(0);
//            }
//
//            if (!root.remov)
//            {
//                indexMap.erase({ root.groupP, root.groupQ });
//                return root;
//            }
//        }
//        return HeapItem{ -1.0, -1, -1, true };
//    }
//    void mark(int groupP, int groupQ)
//    {
//        if (indexMap.find({ groupP, groupQ }) == indexMap.end()) 
//            return;
//
//        int i = indexMap.at({ groupP, groupQ });
//        heapArray[i].remov = true;
//    }
//
//    void insert(const HeapItem& item)
//    {
//        heapArray.push_back(item);
//        int i = heapArray.size() - 1;
//        update(i);
//        heapifyup(i);
//    }
//};
//double distcal(const Point& p1, const Point& p2)
//{
//    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
//}
//
//
//void display(const vector<list<int>>& groups, int N, const vector<Point>& points)
//{
//    cout << "OUTPUT Q2:" << endl;
//
//    int groupCount = 1;
//    for (int i = 0; i < N; ++i) 
//    {
//       if (!groups[i].empty())
//       {
//            cout << "group " << groupCount++ << ": { ";
//            for (int pointIndex : groups[i])
//            {
//                cout << "P" << pointIndex << " (" << fixed << setprecision(1)
//                    << points[pointIndex - 1].x << ", "
//                    << points[pointIndex - 1].y << ") ";
//            }
//            cout << "}\n";
//        }
//    }
//}
//void efficientClustering() {
//    int N;
//    int M; 
//
//    cout << "enter total number of groups(N): ";
//    
//    if (!(cin >> N)) { return; }
//
//    cout << "enter target number of groups(M): ";
//    
//    if (!(cin >> M)) { return; }
//
//    if (M >= N || N <= 1) {
//        cerr << "invalid input: M must be > N (and N > 1) try again\n";
//        return;
//    }
//
//    vector<Point> points(N);
//    cout << "\nEnter coordinates for " << N << " points (x y):\n";
//    for (int i = 0; i < N; ++i) {
//        cout << "Point " << i + 1 << " (x y): ";
//        if (!(cin >> points[i].x >> points[i].y)) {
//            cerr << "error\n";
//            return;
//        }
//    }
//
//    vector<list<int>> groupPoints(N);
//    vector<bool> groupActive(N, true);
//    for (int i = 0; i < N; i++)
//    {
//        groupPoints[i].push_back(i + 1);
//    }
//
//    vector<HeapItem> initialHeapItems;
//
//    for (int i = 0; i < N; i++)
//    {
//        for (int j = i + 1; j < N; j++)
//        {
//            double dist = distcal(points[i], points[j]);
//            initialHeapItems.push_back({ dist, i, j, false });
//        }
//    }
//    MinHeap minHeap;
//    minHeap.buildheap(initialHeapItems);
//
//    int currgrps = N;
//    int iter = 0;
//
//    while (currgrps > M)
//    {
//        iter++;
//        HeapItem minItem = minHeap.extractmin();
//
//        if (minItem.remov) {
//            continue;
//        }
//
//        int p = minItem.groupP; 
//        int q = minItem.groupQ; 
//        double minDistance = minItem.distance;
//
//        if (!groupActive[p] || !groupActive[q]) {
//            continue; 
//        }
//
//        cout << "\n--- Iteration " << iter << " (Current groups: " << currgrps << ") ---\n";
//        cout << "Min distance: " << fixed << setprecision(3) << minDistance;
//        cout << " between G" << p + 1 << " and G" << q + 1 << ".\n";
//
//
//        groupPoints[p].splice(groupPoints[p].end(), groupPoints[q]);
//        groupPoints[q].clear();
//        groupActive[q] = false;
//
//        cout << "Merging G" << q + 1 << " into G" << p + 1 << ".\n";
//
//        for (int k = 0; k < N; ++k)
//        {
//            if (k == p || k == q || !groupActive[k])
//                continue;
//
//            int index_P_K_P = min(p, k);
//            int index_P_K_Q = max(p, k);
//            int index_Q_K_P = min(q, k);
//            int index_Q_K_Q = max(q, k);
//
//            double old_dist_P_K = -1;
//            double old_dist_Q_K = -1;
//
//            if (minHeap.getIndexMap().count({ index_P_K_P, index_P_K_Q }))
//            {
//                int heapIdx = minHeap.getIndexMap().at({ index_P_K_P, index_P_K_Q });
//                old_dist_P_K = minHeap.getHeapArray()[heapIdx].distance;
//                minHeap.mark(index_P_K_P, index_P_K_Q);
//            }
//
//            if (minHeap.getIndexMap().count({ index_Q_K_P, index_Q_K_Q }))
//            {
//                int heapIdx = minHeap.getIndexMap().at({ index_Q_K_P, index_Q_K_Q });
//                old_dist_Q_K = minHeap.getHeapArray()[heapIdx].distance;
//                minHeap.mark(index_Q_K_P, index_Q_K_Q);
//            }
//
//            double newDist;
//            if (old_dist_P_K == -1)
//                newDist = old_dist_Q_K;
//            else if (old_dist_Q_K == -1)
//                newDist = old_dist_P_K;
//            else
//                newDist = min(old_dist_P_K, old_dist_Q_K);
//
//            int new_P = min(p, k);
//            int new_Q = max(p, k);
//
//            if (newDist > 0)
//            {
//                minHeap.insert({ newDist, new_P, new_Q, false });
//            }
//        }
//        currgrps--;
//    }
//
//    display(groupPoints, N, points);
//}
//
//int main()
//{
//    cout << fixed << setprecision(3);
//    efficientClustering();
//    system("pause");
//
//    return 0;
//}
