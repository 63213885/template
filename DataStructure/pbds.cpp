#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class KT, class VT = null_type>
using RBTree =
	tree<KT, VT, std::less<KT>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)：求平衡树内排名为k的值是多少
// order_of_key(k): 求平衡树内值为k的排名是多少

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	RBTree<int> tr;
	for (int i = 1; i <= 10; i += 2) {
		tr.insert(i);
	}
	debug(tr.order_of_key(1));
	debug(tr.order_of_key(3));
	debug(tr.order_of_key(5));
	debug(tr.order_of_key(7));
	debug(tr.order_of_key(9));
	debug(tr.order_of_key(11));
	debug(tr.order_of_key(-1));
	debug(tr.order_of_key(2));
	cout << endl << endl;
	debug(*tr.find_by_order(3));
	debug(*tr.find_by_order(10));
	
	return 0 ^ 0;
}