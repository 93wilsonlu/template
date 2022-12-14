#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;

using ordered_set = tree<pair<int, int>,
                         null_type,
                         less<pair<int, int>>,
                         rb_tree_tag,
                         tree_order_statistics_node_update>;
