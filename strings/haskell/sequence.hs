import Control.Monad (filterM)

findSubSequences :: String -> [String]
findSubSequences = filterM $ const [True, False] 

main = traverse print $ findSubSequences "abc"
