int is_digtal(char ch)
{
    if(ch >= '0' && ch <='9')
        return 1;
    return 0;
}
int char_to_digtal(char ch)
{
    return ch - '0';
}
#define INT_MAX  0x7fffffff
#define INT_MIN (-2147483648)
int myAtoi(char * str){
    if(NULL == str)
    {
        return 0;
    }
    int flag = 1;
    int unull_index = 0;
    //过滤空格
    while(str[unull_index]!='\0' && str[unull_index]==' ')
    {
        unull_index++;
    }
    //判断非空格位置是否为有效
    if(str[unull_index] =='\0'  || (!is_digtal(str[unull_index]) &&str[unull_index]!= '-' && str[unull_index]!= '+'))
        return 0;
    if(str[unull_index] == '-')
    {
        flag = -1;
        unull_index++;
    }
    else if(str[unull_index] == '+')
    {
        unull_index++;
    }

    //
    if(!is_digtal(str[unull_index]))
       return 0;
    long long result = 0;
    while(str[unull_index]!='\0')
    {
        if(is_digtal(str[unull_index]))
        {
            if(result > INT_MAX/10 || (result==INT_MAX/10 && (char_to_digtal(str[unull_index]) > 7)))
            {
                if(flag == -1)
                {
                    return INT_MIN;
                }
                else
                {
                    return INT_MAX;
                }
            }
            result = result*10 + char_to_digtal(str[unull_index]);
        }
        else
        {
            break;
        }
        unull_index++;
    }
    if(flag == -1)
    {
        result = result*-1;
    }
    if(result>INT_MAX)
        return INT_MAX;
    if(result< INT_MIN)
        return INT_MIN;
    return result;
}

