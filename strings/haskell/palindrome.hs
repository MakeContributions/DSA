import Control.Monad (ap)

isPalindrome :: String -> Bool
isPalindrome s = s == reverse s

-- point-free style
isPalindrome2 :: String -> Bool
isPalindrome2 = ap (==) reverse

main = traverse print $ isPalindrome <$> ["abba", "abbcccbba", "abbccbbba"]
