using NUnit.Framework;

namespace Algorithms.Tests.Maths

{
    [TestFixture]
    public class NaismithsRule
    {
        [TestCase(121052, 5001, 2362)]
        [TestCase(51022, 1023, 886)]
        [TestCase(91022, 5944, 1994)]
        [TestCase(34992, 421, 580)]
        [TestCase(14012, 2338, 448)]
        [TestCase(301221, 8300, 5464)]

        public void CalculateTime_ShouldGetExpectedResult(int pathLenght, int upHill, double expected)
        {
            double result = Algorithms.Maths.NaismithsRule.ReturnTime(pathLenght, upHill);
            Assert.AreEqual(expected, result);
        }
    }
}