% non-self-balancing 2-3 Trees

/*
Plagiarism Statement
I have read and understood the DCU Academic Integrity & Plagiarism Policy which can be found here: https://www.dcu.ie/system/files/2020-09/1_-_integrity_and_plagiarism_policy_ovpaa-v4.pdf

This work is my own. Any references are cited and acknowledged.
This submission has not been previously submitted by me or any other
person on this course or any other course.
*/

/* Predicates */

% add(X, T1, T2) is true if adding X to the 2-3 Tree T1 generates the
% 2-3 Tree T2.
% member(X, T) is true if X is in the 2-3 Tree T.
% height(T,N) is true if the height of T is N.
% prettyPrint(T) is always true and displays the 2-3 Tree T.

% add(X, T1, T2)

/* binary tree base case */

add(X, nil, tree(X, nil, nil))
 :- !. % adding node to an empty tree creates a tree with node as the root and two empty subtrees

/* 3 tree base cases */

% adding a node to a binary tree with two empty subtrees returns a tree
% with two roots

add(X, tree(Y, nil, nil), tree(X, Y, nil, nil, nil)) :-
      X < Y,            % smaller node first, larger node second
      !.

add(X, tree(Y, nil, nil), tree(Y, X, nil, nil, nil)) :-
      X > Y,            % smaller node first, larger node second
      !.

/* add to middle subtree */

add(X, tree(Y1, Y2, L, M, R), tree(Y1, Y2, L, M1, R)) :-
      X > Y1,           % check if number is inbetween the two root nodes
      X < Y2,
      !,
      add(X, M, M1).    % add to middle

/* add to left subtree */

add(X, tree(Y1, Y2, L, M, R), tree(Y1, Y2, L1, M, R)) :-
      X =< Y1,                 % if not a middle node, check if it's smaller or equal to the first root node
      !,
      add(X, L, L1).           % add to left

/* add to right subtree */

add(X, tree(Y1, Y2, L, M, R), tree(Y1, Y2, L, M, R1)) :-
      X > Y2,                   % else, check it is larger than the right root node
      !,
      add(X, R, R1).            % add to right

% member(X, T)

/* binary tree base case */

ismember(X, tree(X, _, _)) :- !.         % check binary tree root

/* 3 tree base case */

ismember(X, tree(Y, X, _, _, _)) :- X > Y, !.  % check 3 tree roots
ismember(X, tree(X, Y, _, _, _)) :- X < Y, !.

/* search middle subtree for X */

ismember(X, tree(Y1, Y2, _, M, _)) :-
      X > Y1,                     % check X is inbetween the 3 tree's roots
      X < Y2,
      !,
      ismember(X, M).             % check middle subtree

/* search left subtree for X */

ismember(X, tree(Y, _, L, _, _)) :-
      X =< Y,                               % check if X is equal to or less than the first root
      !,
      ismember(X, L).                       % check left subtree

/* search right subtree for X */

ismember(X, tree(_, Y, _, _, R)) :-
      X > Y,                                 % check if X is greater than the second root
      ismember(X, R).                        % search right subtree

% height(T, H)

/* base case */

height(nil, 0 ).                                      % empty tree: height is 0

/* binary tree */

height(tree(_,L,R), H ) :-                            % height of a binary tree
      height(L, Lheight),                             % take height of left subtree
      height(R, Rheight),                             % take height of right subtree
      H is max(Lheight, Rheight) + 1.                 % max height using max() and add 1

/* 3 tree */

height(tree(_, _, L, M, R), H) :-                     % height of a 3 tree
       height(M, Mheight),                            % take height of middle subtree
       height(L, Lheight),                            % take height of left subtree
       height(R, Rheight),                            % take height of right subtree
       max_list([Lheight, Mheight, Rheight], Max),    % find max height using a max_list()
       H is Max + 1.                                  % add 1 to max height

% prettyPrint(T).

/* References for pretty print:
 *  http://www.tcl-sfs.uni-tuebingen.de/~cornell/prolog/Trees.html
 *  http://users.utcluj.ro/~cameliav/lp/lab8.pdf
*/

prettyPrint(nil).  % base case

/* pretty print binary tree */

prettyPrint(tree(X, L, R)) :-
      Tab = 0,                               % don't print any initial tabs before root
      ppTree(tree(X, L, R), Tab).            % send the tree and tab/s number to ppTree

prettyPrint(tree(X, Y, L, M, R)) :-          % 2-3 tree
      Tab = 0,
      ppTree(tree(X, Y, L, M, R), Tab).


ppTree(nil, Tab) :- printKey(nil, Tab).      % if node is nil, send tab to printKey

ppTree(tree(X, L, R), Tab) :-                % binary tree
      T is Tab + 1,                          % add 1 to Tab, prints 1 tab inbetween each node
      ppTree(L, T),                          % send left subtree to pptree with new tab
      printKey(X, Tab),                      % send root node to printKey
      ppTree(R, T).                          % send right subtree to pptree with new tab

ppTree(tree(X, Y, L, M, R), Tab) :-          % 3 tree
      T is Tab + 1,
      ppTree(L, T),
      printKey(X, Y, Tab),                   % send root nodes to printKey
      ppTree(M, T),                          % send middle subtree to pptree with new tab
      ppTree(R, T).

printKey(X, Y, Tab) :-                       % 3 tree
      Tab > 0, !,                            % if Tab greater than 0 continue
      T is Tab - 1,                          % take away 1 from Tab
      write('\t'),                           % print one tab to screen
      printKey(X, Y, T).                     % send the nodes to print Key again with the new Tab

printKey(X, Y, _) :-                         % 3 tree
      write(X),                              % if Tab is now 0 print the nodes
      write(','),
      write(Y),
      nl.                                    % new line, only 1 new line here so we can see which is the middle node clearly

printKey(X, Tab) :-                          % binary
      Tab > 0,
      !,
      T is Tab - 1,
      write('\t'),
      printKey(X, T).

printKey(X, _) :-                            % binary
      write(X),
      nl, nl, nl. % 3 newlines to seperate nodes clearly screen











