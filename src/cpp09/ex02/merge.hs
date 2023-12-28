
data Element a = Element a | Pair Element Element
type Paired a = {
    elements :: [Element a],
    leftover :: Maybe (Element a)
}

instance Ord Element where
  compare x y = compare (max x) (max y)

max :: Element a -> a
toInt (Element x) = x
toInt (Pair x y)  = max (max x) (max y)

-- TODO
sort :: [Element a] -> [Element a]
sort []  = []
sort [x] = [x]
sort xs  = merge (sort left) (sort right)
  where
    (left, right) = split xs

-- TODO 
makepairs :: [Element a] -> [Element a]
makepairs []  = []
makepairs [x] = [x]
