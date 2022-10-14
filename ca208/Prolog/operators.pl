% Fibonacci
fib(0, 1) :- !.
fib(1, 1) :- !.

% Y is the fibonacci number of X.
% The Fibonacci Number of X is the sum of the Fibonacci Numbers of (X-1)
% and (X-2), for X > 1.
% The Fibonacci Number of 1 is 1.
% The Fibonacci Number of 0 is 1.
%
% Y is the Xth term in the Fibonacci Sequence
%
% ! at the end: once it finds an answer it wont backtrack, as we dont
% need to find any other answers because there are none.

fib(X, Y) :- X > 1, X1 is X-1, fib(X1,Y1), X2 is X-2, fib(X2,Y2), Y is Y1 + Y2, !.

% ---------------------


% Area	of a triangle

% Define an infix binary operator, tA, that is true if the right operand
% is the area of a triangle defined by the left operand, A triange A/B
% has a base of A and a perpendicular height of B. For example, the
% clause 6/4 tA X is true if the value is 12.

:- op(500, yfx, tA).
tA(B/H, A) :- A is (B // 2) * H.
