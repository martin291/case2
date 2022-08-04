% RULES

% This relation is true if X is the first element of list A.
myHead(X, [X|_]).

% This relation is true if X is an element of list A.
myElem(X, A) :- myHead(X, A).
myElem(X, [_|Tail]) :- myElem(X, Tail).

% This relation is true if list A is the tail of list B.
myTail(X, [_|X]).

% This relation is true if X is the last element of list A.
myLast(X, [X]).
myLast(X, [_|Y]) :- myLast(X, Y).

% This relation is true if list C is list B appended to the end of list
% A.
myAppend([], L, L).
myAppend([X|L1], L2, [X|L3]) :- myAppend(L1, L2, L3).
%
% This relation is true if list B is list A with the first occurrence of X removed.
myDelete(L1, L2, L3) :- myAppend(L3, L2, L1).

% This relation is true if list A is the reverse of list B.
myReverse([], []).
myReverse([X], [X]).
myReverse([H|T], B):- myReverse(T, A), myAppend(A, [H], B).

