% Facts

north(k, p).
north(f, k).
north(a, f).

north(l, q).
north(g, l).
north(b, g).

north(m, r).
north(h, m).
north(c, h).

north(n, s).
north(i, n).
north(d, i).

north(o, t).
north(j, o).
north(e, j).

east(q, p).
east(r, q).
east(s, r).
east(t, s).

east(l, k).
east(m, l).
east(n, m).
east(o, n).

east(g, f).
east(h, g).
east(i, h).
east(j, i).
east(b, a).
east(c, b).
east(d, c).
east(e, d).

% Rules

south(X, Y) :- north(Y, X).
west(X, Y) :- east(Y, X).

north_west(X, Y) :- north(X, Z), west(Z, Y).
north_east(X, Y) :- north(X, Z), east(Z, Y).

south_west(X, Y) :- south(X, Z), west(Z, Y).
south_east(X, Y) :- south(X, Z), east(Z, Y).

duenorth(X, Y) :- north(X, Y).
duenorth(X, Y) :- north(X, Z), duenorth(Z, Y).

duesouth(X, Y) :- south(X, Y).
duesouth(X, Y) :- south(X, Z), duesouth(Z, Y).

dueeast(X, Y) :- east(X, Y).
dueeast(X, Y) :- east(X, Z), dueeast(Z, Y).

duewest(X, Y) :- west(X, Y).
duewest(X, Y) :- west(X, Z), duewest(Z, Y).

duenortheast(X, Y) :- duenorth(X, Z), dueeast(Z, Y).
duenorthwest(X, Y) :- duenorth(X, Z), duewest(Z, Y).
duesoutheast(X, Y) :- duesouth(X, Z), dueeast(Z, Y).
duesouthwest(X, Y) :- duesouth(X, Z), duewest(Z, Y).






















