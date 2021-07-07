#include "TrustCenter.h"
#include "Alice.h"
#include "Bob.h"

#include <iostream>

using namespace std;

int main()
{
	TrustCenter TR;
	TR.GenKeys();
	Alice* a = new Alice();
	Bob* b = new Bob();
	int x = a->Alice_make_x(TR.p, TR.q, TR.q);
	int e = b->Bob_gen_e();
	int s = a->Alice_make_s(TR.w, e, TR.q);
	b->Bob_check(TR.g, s, TR.y, TR.p, x);
}