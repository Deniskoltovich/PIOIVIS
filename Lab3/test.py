import unittest

from func import unique_permutations


class MyTestCase(unittest.TestCase):
    def test0(self):
        self.assertEqual(unique_permutations([1, 2, 3]),
                         [(1, 2, 3), (2, 1, 3), (2, 3, 1), (1, 3, 2), (3, 1, 2), (3, 2, 1)])
    def test1(self):
        self.assertEqual(unique_permutations([345, '1d', -3]),
                         [(345, '1d', -3), ('1d', 345, -3), ('1d', -3, 345), (345, -3, '1d'), (-3, 345, '1d'), (-3, '1d', 345)])
    def test2(self):
        self.assertEqual(unique_permutations([1,2]), [(1,2), (2,1)])
        
if __name__ == '__main__':
    unittest.main()
