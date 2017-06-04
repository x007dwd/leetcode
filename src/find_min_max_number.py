import sys
def get_num_type(num):
    ret_code = 2  #2 -> positive num, 1 -> negtive num, 0 -> illegal num
    bit_index = 0
    for bit in num:
        if cmp(bit, '0') < 0 or cmp(bit, '9') > 0:
            if bit_index == 0 and cmp(bit, '-') == 0:
                ret_code = 1
            else:
                ret_code = -1
                break
        bit_index = bit_index + 1
    return ret_code;

def normalize_num(num):
    num_type = get_num_type(num)
    if num_type == -1:
        return -1, num
    
    if len(num) == 0:
        return -1, num
    
    bit_index = 0
    is_MSB = 0
    ret_num = ''
    for bit in num:
        if bit_index == 0 and cmp(bit, '-') == 0:
            ret_num += bit
        elif cmp(bit, '0') > 0:
            ret_num += bit
            is_MSB = 1
        elif cmp(bit, '0') == 0 and is_MSB == 1:
            ret_num += bit
        bit_index += 1
    if cmp(ret_num, "") == 0:
        ret_num = '0'
    return 0, ret_num   
        

def find_natural_num(natural_num):
    if cmp(natural_num, '0') == 0:
        return -1, num
    natural_num = '0' + natural_num
    bit_idx = len(natural_num) - 2
    low_bits_sum = ord(natural_num[-1]) - ord('0') - 1
    for bit in natural_num[::-1][1:]:
        if low_bits_sum >= 0 and cmp(bit, '9') < 0:
            natural_num =  natural_num[:bit_idx] + chr(ord(natural_num[bit_idx]) + 1) + natural_num[bit_idx + 1:]
            break
        low_bits_sum += ord(natural_num[bit_idx]) - ord('0')
        bit_idx -= 1
    
    mod_idx = len(natural_num) - 1
    for bit in natural_num[bit_idx + 1:]:
        if low_bits_sum >= 9:
            natural_num = natural_num[:mod_idx] + '9' + natural_num[mod_idx + 1:]
            low_bits_sum -= 9
        else:
            natural_num = natural_num[:mod_idx] + str(low_bits_sum) + natural_num[mod_idx+ 1:]
            low_bits_sum = 0
        mod_idx -= 1
    if cmp(natural_num[0], '0') == 0:
        return 0, natural_num[1:]
    else:
        return 0, natural_num

def find_neg_num(neg_num):
    neg_num = '0' + neg_num[1:]
    bit_idx = len(neg_num) - 2
    low_bits_sum = ord(neg_num[bit_idx + 1]) - ord('0') + 1
    normal_flag = 0
    for bit in neg_num[::-1][2:]:
        if low_bits_sum / (len(neg_num) - 1 - bit_idx) > 9 or neg_num[bit_idx] == '0': 
            low_bits_sum += ord(bit) - ord('0')
            continue
        if cmp(neg_num[bit_idx], '0') > 0:
            neg_num = neg_num[:bit_idx] + chr(ord(neg_num[bit_idx]) - 1) + neg_num[bit_idx + 1:]
            normal_flag = 1
            break
        bit_idx += 1
    if normal_flag == 0:
        return 0, neg_num[1:]
    
    mod_idx = bit_idx + 1
    for bit in neg_num[bit_idx + 1:]:
        if low_bits_sum >=9:
            neg_num = neg_num[:mod_idx] + '9' + neg_num[mod_idx + 1:]
            low_bits_sum -= 9
        else:
            neg_num = neg_num[:mod_idx] + str(low_bits_sum) + neg_num[mod_idx + 1:]
            low_bits_sum = 0
        mod_idx += 1
    return 0, '-' + neg_num[1:] 

def find_num(num):
    num_type = get_num_type(num)
    if num_type == -1:
        return -1, num
    
    if num_type == 2:
        return find_natural_num(num)

    if num_type == 1:
        return find_neg_num(num)

def check_ret_code(ret_code):
    if ret_code != 0:
        print "error: the input number is invalid or there is no anwser."
        sys.exit(1)
    

if __name__ == "__main__":
    
    if len(sys.argv[1]) >= 100:
        print "error: input number's length is biger than 100."
        sys.exit(1)

    num = sys.argv[1].rstrip().lstrip()
    [ret_code, num] = normalize_num(num)
    check_ret_code(ret_code)
    [ret_code, ret_num] = find_num(num)
    check_ret_code(ret_code)
    print("raw number: %s"%(num))
    print("anwser: %s"%(ret_num))
