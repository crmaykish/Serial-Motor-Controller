#ifndef BITMACROS_H_
#define BITMACROS_H_

#define bitValue(x)			(1 << x)
#define setBit(P, B)		P |= bitValue(B)
#define clearBit(P, B)		P &= ~bitValue(B)
#define toggleBit(P, B)		P ^= bitValue(B)
#define queryBit(P, B)		(P & bitValue(B))

#endif /* BITMACROS_H_ */