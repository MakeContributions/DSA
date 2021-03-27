import Control.Monad (filterM)

findSubSequences = filterM $ const [True, False] 

main = traverse print $ findSubSequences "abc"
