#include "../base/chef_stringify_stl.hpp"
#include <string>
#include <map>
#include <iostream>
#include "./common/assert_wrapper.hpp"
#include "./common/check_log.hpp"

int main() {
  ENTER_TEST;

  std::string str;

  {
    std::vector<int> vec = {1, 2, 3};
    str = chef::stringify_stl_one<std::vector<int> >(vec,
                                                    "{\n"    ,
                                                    "  \""   ,
                                                    "\""     ,
                                                    ",\n"    ,
                                                    "\n}"    );
    //std::cout << str << std::endl;
    chef::stringify_stl_vector(vec);
    str = chef::stringify_stl_vector<int>(vec);
    assert(str == "[1,2,3]");
    str = chef::stringify_stl_vector<int>(vec,
                                          "{\n"    ,
                                          "  \""   ,
                                          "\""     ,
                                          ",\n"    ,
                                          "\n}"    );
    //std::cout << str << std::endl;
  }

  {
    std::map<int, int> m;
    m[1] = 100;
    m[2] = 200;
    m[3] = 300;
    str = chef::stringify_stl_two<std::map<int, int> >(m,
                                                      "{\n"    ,
                                                      "  \""   ,
                                                      "\""     ,
                                                      ": "     ,
                                                      ""       ,
                                                      ""       ,
                                                      ",\n"    ,
                                                      "\n}"    );
    //std::cout << str << std::endl;
    chef::stringify_stl_map(m);
    str = chef::stringify_stl_map<int, int>(m);
    assert(str == "{1:100,2:200,3:300}")
    str = chef::stringify_stl_map<int, int>(m,
                                            "{\n"    ,
                                            "  \""   ,
                                            "\""     ,
                                            ": "     ,
                                            ""       ,
                                            ""       ,
                                            ",\n"    ,
                                            "\n}"    );
  }

  {
    std::array<int, 3> arr = {1, 2, 3};
    str = chef::stringify_stl_array<int, 3>(arr);
    assert(str == "[1,2,3]");
  }

  {
    std::deque<int> ct = {1, 2, 3};
    str = chef::stringify_stl_deque<int>(ct);
    assert(str == "[1,2,3]");
  }

  {
    std::forward_list<int> ct = {1, 2, 3};
    str = chef::stringify_stl_forward_list<int>(ct);
    assert(str == "[1,2,3]");
  }

  {
    std::list<int> ct = {1, 2, 3};
    str = chef::stringify_stl_list<int>(ct);
    assert(str == "[1,2,3]");
  }

  {
    std::set<int> ct = {1, 2, 3};
    str = chef::stringify_stl_set<int>(ct);
    assert(str == "[1,2,3]")
  }

  {
    std::unordered_set<int> ct = {1, 2, 3};
    str = chef::stringify_stl_unordered_set<int>(ct);
    //std::cout << chef::stringify_stl_unordered_set<int>(ct) << std::endl;
  }

  {
    std::multiset<int> ct = {1, 1, 2, 3};
    str = chef::stringify_stl_multiset<int>(ct);
    assert(str == "[1,1,2,3]");
  }

  {
    std::unordered_multiset<int> ct = {1, 2, 3};
    //std::cout << chef::stringify_stl_unordered_multiset<int>(ct) << std::endl;
  }

  {
    std::multimap<int, int> m;
    m.insert(std::make_pair(1, 100));
    m.insert(std::make_pair(2, 200));
    m.insert(std::make_pair(3, 300));
    str = chef::stringify_stl_multimap<int, int>(m);
    assert(str == "{1:100,2:200,3:300}")
  }

  {
    std::unordered_map<int, int> m;
    m.insert(std::make_pair(1, 100));
    m.insert(std::make_pair(2, 200));
    m.insert(std::make_pair(3, 300));
    //std::cout << chef::stringify_stl_unordered_map<int, int>(m) << std::endl;
  }

  {
    std::unordered_multimap<int, int> m;
    m.insert(std::make_pair(1, 100));
    m.insert(std::make_pair(2, 200));
    m.insert(std::make_pair(3, 300));
    //std::cout << chef::stringify_stl_unordered_multimap<int, int>(m) << std::endl;
  }

  {
    std::stack<int> s;
    s.push(1);s.push(2);s.push(3);s.push(5);
    //std::cout << chef::stringify_stl_stack(s) << std::endl;
    assert(s.size() == 4 && s.top() == 5);
  }

  {
    std::queue<int> q;
    q.push(1);q.push(2);q.push(3);q.push(5);q.pop();
    //std::cout << chef::stringify_stl_queue(q) << std::endl;
    assert(q.size() == 3 && q.front() == 2 && q.back() == 5);
  }

  {
    std::priority_queue<int> q;
    q.push(1);q.push(2);q.push(4);q.push(5);q.pop();
    //std::cout << chef::stringify_stl_priority_queue(q) << std::endl;
    assert(q.size() == 3 && q.top() == 4);
  }

  return 0;
}

