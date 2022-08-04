#include "LRU_lib.h"

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int max_size, val, h, e, cnt = 0;

	initNodeList(max_size, h, e);

	printProcess(h, cnt);

	while(cin >> val) {

		if (!pro_map.count(val)) deleteTailNode(e), appendHeadNode(h, val);
		else updateNodeList(val, h, e);

		printProcess(h, cnt);
	}
	return 0;
}
