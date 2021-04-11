def equalize_strings(x, y):
  """
  >>> def eq_str(x, y):
  ...   max_len = max(len(x), len(y))
  ...   return x.zfill(max_len), y.zfill(max_len), max_len
  >>>
  >>> all(equalize_strings(x, y) == eq_str(x, y) for x, y
  ...   in (('x' * i, 'y' * (i // 2)) for i in range(10)))
  True
  """
  n = len(x)
  m = len(y)
  zeros = abs(n - m) * '0'
  if n > m:
    y = zeros + y
  elif m > n:
    x = zeros + x
  return x, y, len(x)

def sum(x, y):
  """
  >>> all(sum(str(x), str(y)) == str(x + y) for x, y
  ...   in ((0, 0), (0, 1), (1, 1234567890), (543210, 9876543)))
  True
  """
  x, y, size = equalize_strings(x, y)
  carry = 0
  result = ''
  for i in range(1, size+1):
    # print(i)
    dgt1 = int(x[size - i])
    dgt2 = int(y[size - i])
    dgt3 = (dgt1 + dgt2 + carry) % 10
    result = str(dgt3) + result
    carry = int((dgt1 + dgt2 + carry) / 10)
    # print(dgt1, dgt2, dgt3, result, carry)

  if carry:
    result = '1' + result
  return result

def subtract(x, y):
  """
  >>> subtract("0", "0")
  '0'
  >>> subtract("1", "0")
  '1'
  >>> subtract("0", "1")  # This should be -1!!
  '1'
  """
  x, y, size = equalize_strings(x, y)
  carry = 0
  result = ""
  for i in range(size):
    if y[i] < x[i]:
      break
    elif x[i] < y[i]:
      tmp = x
      x = y
      y = tmp
      break

  for i in range(1, size+1):
    dgt1 = int(x[size - i])
    dgt2 = int(y[size - i])
    dgt3 = dgt1 - dgt2 - carry
    if dgt3 < 0:
      dgt3 += 10
      carry = 1
    else:
      carry = 0
    result = str(dgt3) + result
  return result

def kmul(x ,y):
  """
  >>> all(kmul(str(x), str(y)) == str(x * y) for x, y
  ...   in ((0, 0), (0, 1), (1, 1234567890), (543210, 9876543)))
  True
  """
  x, y, size = equalize_strings(x, y)
  if size == 1:
    return str(int(x) * int(y))
  mid = int(size / 2)
  a = x[:mid]
  b = x[mid:]
  c = y[:mid]
  d = y[mid:]
  ac = kmul(a, c)
  bd = kmul(b, d)
  ab_cd = kmul(sum(a, b), sum(c, d))
  ad_bc = subtract(ab_cd, sum(ac, bd))
  zeros = "0" * (size - mid)

  result = sum(ac + 2 * zeros, ad_bc + zeros)
  result = sum(result, bd)
  result = result.lstrip('0')
  return result

if __name__ == "__main__":
  x = "134231412"
  y = "141324"
  print(kmul(x, y))
