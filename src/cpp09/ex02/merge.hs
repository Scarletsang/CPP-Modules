
data Element a = Element a | Pair Element Element deriving (Show, Ord, Eq)

instance Ord Element where
  compare x y = compare (max x) (max y)

unwrap :: Element a -> a
unwrap (Element x) = x
unwrap (Pair x y)  = max (unwrap x) (unwrap y)

createPair :: a -> a -> Element a
createPair x y = if x > y then Pair x y else Pair y x

createPair :: Element a -> Element a -> Element a
createPair x y = if unwrap x > unwrap y then Pair x y else Pair y x

max :: Element a -> Element a
max (Element x) = Element x
max (Pair x y)  = x

min :: Element a -> Element a
min (Element x) = Element x
min (Pair x y)  = y

-- TODO
sort :: [Element a] -> [Element a]
sort []  = []
sort [x] = [x]
sort xs  = undefined

makePairs :: [Element a] -> ([Element a], Maybe (Element a))
makePairs []  = ([], Nothing)
makePairs [x] = ([], Just x)
makePairs [x:y:xs] =
    let (elements, leftover) = makePairs xs
    in (createPair x y : elements, leftover)

-- split a list of elements into main chain and pend chain
split :: [Element a] -> ([Element a], [Element a])
split [] = ([], [])
split xs = 
    let (main, pend) = split' xs
    in (min (head xs) : main, pend)

split' :: [Element a] -> ([Element a], [Element a])
split' = foldr (\element (main, pend) -> (max element : main, min element : pend)) ([], [])

-- insertion sort
insert :: ([Element a], [Element a]) -> [Element a]
insert = undefined