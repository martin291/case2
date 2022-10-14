% Classifying Numbers

% zero, negative or positive

class(0, zero) :- !.
class(X, negative) :- X < 0, !.
class(X, positive) :- X > 0, !.

%Splitting Numbers

% split( [], [], []).                             //ATTEMPT
% split([H|T], Positive, Negative) :- H > -1, member(H, Positive),
% delete(H, Positive, X), split(T, X, Negative).
% split([H|T], Positive, Negative) :- H < 0, member(H, Negative),
% delete(H, Negative, %X), split(T, Positive, X).
%
%
% split([-1, -2, 1, 2], [1, 2, 3], [-1, -2, -3]).

split([], _, _).

split([X|Nums1], Pos, Neg) :-
    X >= 0, !, member(X, Pos), delete(Pos, X, Pos1), split(Nums1, Pos1, Neg).

split([X|Nums1], Pos, Neg) :-
    X < 0, !, member(X, Neg), delete(Neg, X, Neg1), split(Nums1, Pos, Neg1).

% David's Method
%
% split2([-1, 1, 2], [1, 2], [-1]).
% split2([-1, -2, 1, 2], Pos, Neg).
split2([], [], []).

split2([X | Nums1], [X|Pos], Neg) :-
    X >= 0, !, split2(Nums1, Pos, Neg).

split2([X | Nums1], Pos, [X|Neg]) :-
    X < 0, !, split2(Nums1, Pos, Neg).

% Fibonacci with cut

%
% Fibonacci Numbers using memoization
%

:- dynamic fib/2.           % Need to declare that the relation fib with 2 arguments
                            % is dynamic and can updated at runtime.

fib(0,0).
fib(1,1).

fib(X,N) :- X1 is X-1, X2 is X-2,
	    fib(X1,N1), fib(X2,N2), N is N1 + N2,
	    asserta(fib(X,N)),           % add fib(X,N) to the database of facts so we don't have to recalculate it, just look it up
            !.
