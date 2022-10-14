/* FACTS */

parents(david, george, noreen).
parents(jennifer, george, noreen).
parents(georgejr, george, noreen).
parents(scott, george, noreen).
parents(joanne, george, noreen).
parents(jessica, david, edel).
parents(clara, david, edel).
parents(michael, david, edel).
parents(laura, georgejr, susan).
parents(anna, scott, siobhan).


parent(george, david).
parent(george, jennifer).
parent(george, scott).
parent(george, joanne).
parent(noreen, david).
parent(noreen, jennifer).
parent(noreen, scott).
parent(noreen, joanne).
parent(david, jessica).
parent(david, clara).
parent(david, michael).
parent(edel, jessica).
parent(edel, clara).
parent(edel, michael).
parent(georgejr, laura).
parent(susan, laura).
parent(scott, anna).
parent(siobhan, anna).

/* Relationships */

father(X, Y) :- parents(Y, X, _).
male(X) :- father(X, _).

mother(X, Y) :- parents(Y, _, X).
female(X) :- mother(X, _).

grandfather(X, Y) :- father(X, Z), father(Z, Y).
grandfather(X, Y) :- father(X, Z), mother(Z, Y).

grandmother(X, Y) :- mother(X, Z), mother(Z, Y).
grandmother(X, Y) :- mother(X, Z), father(Z, Y).

different(X, Y) :- X \= Y.

brother(X, Y) :- male(X), father(Z, X), father(Z, Y), different(X, Y).
brother(X, Y) :- male(X), mother(Z, X), mother(Z, Y), different(X, Y).

sister(X, Y) :- female(X), father(Z, X), father(Z, Y), different(X, Y).
sister(X, Y) :- female(X), father(Z, X), father(Z, Y), different(X, Y).

% uncle(X, Y) :- parents(Y, Z, Q), (brother(X, Z) ; brother(X, Q)).

% uncle(X, Y) :- ((father(Z, Y), brother(X, Z)) ; (mother(Z, Y),
% brother(X, Z))), X \= Z.

uncle(X, Y) :- parent(Z, Y), brother(X, Z).

%  aunt(X, Y) :- ((father(Z, Y), sister(X, Z)) ; (mother(Z, Y),
%  sister(X, Z))), X \= Z.

aunt(X, Y) :- parent(Z, Y), sister(X, Z).

cousin(X, Y) :- parent(Z, Y), aunt(Z, X), different(X, Y).
cousin(X, Y) :- parent(Z, Y), uncle(Z, X), different(X, Y).














