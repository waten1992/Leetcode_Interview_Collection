int ladderLength(const string &start , const string &end , const unordered_set<string> &dict)
{
    queue<string> cuurent , next ;
    unordered_set<string> vistited;
    int level = 0 ;
    bool found = flase;
    auto state_is_target = [&](const string &s) // 任何被使用到的外部變數皆隱式地以參考方式加以引用。
    {
        return s == end;
    };
    auto state_extend = [&](const string &s)
    {
        vector<string> result;
        for (size_t i = 0; i < s.size(); ++i)
        {
            string new_word(s);
            for (char c = 'a'; c <= 'z'; c++)
            {
                if (c == new_word[i]) continue;
                swap(c, new_word[i]);
                if (dict.count(new_word) > 0 &&
                        !visited.count(new_word))
                {
                    result.push_back(new_word);
                    visited.insert(new_word);
                }
                swap(c, new_word[i]); // 恢复该单词
            }
        }
        return result;
    };
    current.push(start);
    while (!current.empty() && !found)
    {
        ++level;
        while (!current.empty() && !found)
        {
            const string str = current.front();
            current.pop();
            const auto& new_states = state_extend(str);
            for (const auto& state : new_states)
            {
                next.push(state);
                if (state_is_target(state))
                {
                    found = true; //找到了
                    break;
                }
            }
        }
        swap(next, current);
    }
    if (found) return level + 1;
    else return 0;
}


