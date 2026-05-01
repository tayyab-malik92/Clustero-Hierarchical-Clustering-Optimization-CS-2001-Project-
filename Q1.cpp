//#include<iostream>
//
//#include<vector>
//#include<cmath>
//#include<iomanip>
//#include<algorithm>
//#include<list>
//#include<string>
//using namespace std;
//
//struct Point
//{
//    double x;
//    double y;
//};
//
//// Function for calculating distance b/w points
//double distancecal(const Point& p1, const Point& p2)
//{
//    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
//}
//
//void disgroups(const vector<list<int>>& groups, int N, const vector<Point>& points)
//{
//    
//    cout << "OUTPUT Q1 (Final Groups)\n";
//    
//
//    int groupCount = 1;
//    for (int i = 0; i < N; ++i)
//    {
//        if (!groups[i].empty())
//        {
//            cout << "Group " << groupCount++ << ": { ";
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
//
//void basicClustering()
//{
//    int N; 
//    int M;
//    cout << "Enter the total number of points (N): ";
//
//    if (!(cin >> N))
//    {
//        cerr << "Invalid input for N. Exiting.\n";
//        return;
//    }
//
//    cout << "Enter the target number of groups (M): ";
//    if (!(cin >> M))
//    {
//        cerr << "Invalid input for M. Exiting.\n";
//        return;
//    }
//
//    if (M >= N || N <= 1)
//    {
//        cerr << "Invalid input: M must be less than N (and N > 1).\n";
//        return;
//    }
//
//
//    vector<Point> points(N);
//    cout << "\nEnter coordinates for " << N << " points (x y):\n";
//    for (int i = 0; i < N; i++)
//    {
//        cout << "Point " << i + 1 << " (x y): ";
//       
//        if (!(cin >> points[i].x >> points[i].y))
//        {
//            cerr << "ERROR: Failed to read coordinates. Exiting.\n";
//            
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            return;
//        }
//    }
//    vector<vector<double>> matrix(N, vector<double>(N));
//    vector<list<int>> groupPoints(N);
//
//    for (int i = 0; i < N; i++)
//    {
//        groupPoints[i].push_back(i + 1);
//    }
//    cout << "\nCalculating initial " << N << "x" << N << " distance matrix...\n";
//    for (int i = 0; i < N; i++)
//    {
//        for (int j = i + 1; j < N; j++)
//        {
//            matrix[i][j] = distancecal(points[i], points[j]);
//        }
//    }
//
//    int currgrps = N;
//    int iter = 0;
//    while (currgrps > M)
//    {
//        iter++;
//        cout << "\n Iteration " << iter << " (Current groups: " << currgrps << ") \n";
//
//        double mindist = -1.0;
//        int indexP = -1;
//        int indexQ = -1;
//
//        for (int i = 0; i < N; i++)
//        {
//            if (groupPoints[i].empty())
//                continue;
//
//            for (int j = i + 1; j < N; j++)
//            {
//                if (groupPoints[j].empty())
//                    continue;
//
//                double dist = matrix[i][j];
//
//                if (dist > 0 && (mindist < 0 || dist < mindist))
//                {
//                    mindist = dist;
//                    indexP = i;
//                    indexQ = j;
//                }
//            }
//        }
//
//        if (indexP == -1)
//        {
//            cerr << "Error: Could not find minimum distance. Stopping.\n";
//            break;
//        }
//
//        cout << "Minimum distance found: " << fixed << setprecision(3) << mindist;
//        cout << " between Groups G" << indexP + 1 << " and G" << indexQ + 1 << ".\n";
//
//        int p = indexP; 
//        int q = indexQ; 
//
//        
//        groupPoints[p].splice(groupPoints[p].end(), groupPoints[q]);
//        groupPoints[q].clear(); 
//
//        cout << "Merging G" << q + 1 << " into G" << p + 1 << ".\n";
//
//        for (int k = 0; k < N; k++)
//        {
//            if (k == p || groupPoints[k].empty())
//                continue;
//
//           
//            double dist_P_K;
//            if (p < k)
//                dist_P_K = matrix[p][k];
//            else
//                dist_P_K = matrix[k][p];
//            double dist_Q_K;
//            if (q < k)
//                dist_Q_K = matrix[q][k];
//            else
//                dist_Q_K = matrix[k][q];
//
//            double newDist = min(dist_P_K, dist_Q_K);
//
//            if (p < k)
//                matrix[p][k] = newDist;
//            else
//                matrix[k][p] = newDist;
//            if (q < k)
//                matrix[q][k] = 0.0;
//            else
//                matrix[k][q] = 0.0;
//        }
//
//        currgrps--;
//    }
//
//    disgroups(groupPoints, N, points);
//}
//
//int main()
//{
//    cout << fixed << setprecision(3);
//    basicClustering();
//    system("pause");
//
//
//    return 0;
//}
