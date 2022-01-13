"""
https://en.wikipedia.org/wiki/Karatsuba_algorithm
"""


def equalize_strings(x_value, y_value):
    """
        >>> def eq_str(x, y):
        ...   max_len = max(len(x), len(y))
        ...   return x.zfill(max_len), y.zfill(max_len), max_len
        >>>
        >>> all(equalize_strings(x, y) == eq_str(x, y) for x, y
        ...   in (('x' * i, 'y' * (i // 2)) for i in range(10)))
        True
    """
    n_value = len(x_value)
    m_value = len(y_value)
    zeros = abs(n_value - m_value) * '0'
    if n_value > m_value:
        y_value = zeros + y_value
    elif m_value > n_value:
        x_value = zeros + x_value
    return x_value, y_value, len(x_value)


def add_function(x_value, y_value):
    """
        >>> all(add_function(str(x), str(y)) == str(x + y) for x, y
        ...   in ((0, 0), (0, 1), (1, 0), (1, 1234567890), (543210, 9876543)))
        True
    """
    x_value, y_value, size = equalize_strings(x_value, y_value)
    carry = 0
    result = ''

    for i in range(1, size+1):
        # print(i)
        dgt1 = int(x_value[size - i])
        dgt2 = int(y_value[size - i])
        dgt3 = (dgt1 + dgt2 + carry) % 10
        result = str(dgt3) + result
        carry = int((dgt1 + dgt2 + carry) / 10)
        # print(dgt1, dgt2, dgt3, result, carry)

    if carry:
        result = '1' + result

    return result


def absolute_difference(x_value, y_value):
    """
        >>> all(absolute_difference(str(x), str(y)) == str(abs(x - y)) for x, y
        ...   in ((0, 0), (0, 1), (1, 0), (1, 1234567890), (543210, 9876543)))
        True
    """
    x_value, y_value, size = equalize_strings(x_value, y_value)
    carry = 0
    result = ""

    for i in range(size):
        if y_value[i] <= x_value[i]:
            break
        #tmp = x_value
        #x_value = y_value
        #y_value = tmp
        x_value, y_value = y_value, x_value
        break

    for i in range(1, size+1):
        dgt1 = int(x_value[size - i])
        dgt2 = int(y_value[size - i])
        dgt3 = dgt1 - dgt2 - carry

        if dgt3 < 0:
            dgt3 += 10
            carry = 1
        else:
            carry = 0
        result = str(dgt3) + result

    return result


def kmul_function(x_value ,y_value):
    """
        >>> all(kmul_function(str(x), str(y)) == str(x * y) for x, y
        ...   in ((0, 0), (0, 1), (1, 0), (1, 1234567890), (543210, 9876543)))
        True
    """
    x_value, y_value, size = equalize_strings(x_value, y_value)
    if size == 1:
        return str(int(x_value) * int(y_value))

    mid = int(size / 2)
    a_value = x_value[:mid]
    b_value = x_value[mid:]
    c_value = y_value[:mid]
    d_value = y_value[mid:]
    ac_value = kmul_function(a_value, c_value)
    bd_value = kmul_function(b_value, d_value)
    ab_cd_value = kmul_function(add_function(a_value, b_value), add_function(c_value, d_value))
    ad_bc_value = absolute_difference(ab_cd_value, add_function(ac_value, bd_value))
    zeros = "0" * (size - mid)
    result = add_function(ac_value + 2 * zeros, ad_bc_value + zeros)
    result = add_function(result, bd_value)
    result = result.lstrip('0')
    return result

if __name__ == "__main__":
    X_VAR = "134231412"
    Y_VAR = "141324"
    print(kmul_function(X_VAR, Y_VAR))
