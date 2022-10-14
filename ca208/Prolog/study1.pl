% union(A,B,C) is true if the list C contains only even numbers in either lists A or B.
% e.g: union([1, 2, 3, 4], [-1, -2, -3, -4], [-4, -2, 2, 4].

union2([],[], []).
union2([X], [], [X]).
union2([], [X], [X]).
union2(A, B, [H|T]) :- mod(H, 2) =:= 0, member(H, A) ; member(H, B), union2(A, B, T).



union3([],[],[]).
union3(List1,[],List1).
union3(List1, [Head2|Tail2], [Head2|Output]):-  \+(member(Head2,List1)), union(List1,Tail2,Output).
union3(List1, [Head2|Tail2], Output):-  member(Head2,List1), union(List1,Tail2,Output).

% Write a Prolog relation oddsquaresum(X, S) that is true when S is the
% sum of the square of all the odd numbers in list X. Note that the list
% x can contain any atom, e.g. [4, oranges, 5, 2, 7, apples, 1]. Hence,
% oddsquaresum([4, oranges, 5, 2, 7, apples, 1], 75) is true.

%oddsquaresum([X], Y):-
%    Z is mod(X,2), Z \= 0, X1 is X ** 2, Y is X1.

oddsquaresum([], 0).

oddsquaresum([H|T], Y) :-
    Z is mod(H,2), Z =:= 0, oddsquaresum(T, Y).

oddsquaresum([H|T], Y) :-
    Z is mod(H,2), Z \= 0,
    oddsquaresum(T, Y1),
    Y is (H * H) + Y1, !.

% Let a bus timetable be represented by a list of routes where each route
% is represented by Start/End/DepatureTime/ArrivalTime. Both
% DepartureTime and ArrivalTime
% are represented by a relation time(Hour,Minutes). Write a Prolog
% relation journey(Start,
% End) that is true if there is a route in the timetable that can get a
% passenger from Start
% to End directly or any number of intermediate stops where there is at
% least 10 minutes
% between the arrival at an intermediate point before the departure of
% the next leg of the
% journey. Assume the clock is a 24 hour clock and all departure and
% arrival times occur
% within the same day.

route(Start/End/DepT/ArrT).
time(H, M).
journey(Start, End).


