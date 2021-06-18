module AcakList where


insert x li =
    if null li then [x]
    else if x <= head li then [x] ++ li
    else [head li] ++ insert x (tail li)

isort li =
    if null li then []
    else insert (head li) (isort (tail li))