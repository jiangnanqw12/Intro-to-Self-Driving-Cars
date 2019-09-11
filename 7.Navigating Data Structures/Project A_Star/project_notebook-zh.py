#!/usr/bin/env python
# coding: utf-8

# # 123 实现一个路线规划编制程序
# 在这个项目中，你将使用`A*`搜索实现一个“Google-maps”风格的路线规划算法。

# In[2]:


# Run this cell first!

from helpers import Map, load_map, show_map
from helper import Maps, load_maps, show_maps
from student_code import shortest_path

get_ipython().run_line_magic('load_ext', 'autoreload')
get_ipython().run_line_magic('autoreload', '2')


# ### Map 基础

# In[ ]:


map_10 = load_map('map-10.pickle')
show_map(map_10)


# 上面的地图（如果你没有看到，请运行代码单元格）
# 
# **如果由于网络问题，仍然不显示地图**
# **请运行show_maps(map_10)，并单击左上角Jupyter回到上级菜单，下载.html文件既可浏览。**
# 
# 显示了一个包含10个交叉点的不连贯网络。左边的两个交叉口相互连接，但它们没有连接到道路网络的其余部分。在上面的图表中，2个节点（交叉点）之间的边缘代表一条文字直线道路，而不仅仅是2个城市的抽象连接。
# 
# 这些`Map`对象有两个属性，你可以使用它们来实现A *搜索：`intersections`和`roads` 。
# 
# **Intersections**
# 
# `intersections`被表示为一个词典。
# 
# 在这个例子中，有10个交点，每个交点用x、y坐标标识。坐标如下所示。你可以将鼠标悬停在上图中的每个点上查看交叉点编号。

# In[ ]:


map_10.intersections


# **Roads**
# 
# `roads`属性是一个列表，如果`i` 是一个交叉点，`roads[i]`包含一个交叉点`i`连接到的所有交叉点列表。

# In[ ]:


# this shows that intersection 0 connects to intersections 7, 6, and 5
map_10.roads[0] 


# In[ ]:


# This shows the full connectivity of the map
map_10.roads


# In[ ]:


# map_40 is a bigger map than map_10
map_40 = load_map('map-40.pickle')
show_map(map_40)


# **如果由于网络问题，仍然不显示地图**
# **请运行show_maps(map_40)，并单击左上角Jupyter回到上级菜单，下载.html文件既可浏览。**
# 
# ### 高级可视化
# 
# 上图显示了一个跨越40个不同交叉点的道路网络（标记为0到39）。
# 
# 生成此地图网络的`show_map`函数还需要一些可选参数，这些参数对于将你要编写的搜索算法的输出可视化可能很有用。
# 
# * `start` - 搜索算法的“开始”节点。
# * `goal`  - “目标”节点。
# * `path`  - 与地图上的有效交叉点访问序列相对应的整数数组。

# In[ ]:


# run this code, note the effect of including the optional
# parameters in the function call.
show_map(map_40, start=5, goal=34, path=[5,16,37,12,34])


# ### 编写你的算法
# 你应该在另一个选项卡中打开文件`student_code.py`并在那里编写你的算法。选择`File > Open`，然后选择上一句所说的这个文件。
# 
# 你编写的算法将负责生成类似上面传入`show_map`的`path`。事实上，当调用相同的地图、起始点和目标点时，如上所述，算法应该生成路径`[5, 16, 37, 12, 34]` 。

# In[ ]:


get_ipython().run_cell_magic('bash', '', '> shortest_path(map_40, 5, 34)\n[5, 16, 37, 12, 34]')


# In[ ]:


path = shortest_path(map_40, 5, 34)
if path == [5, 16, 37, 12, 34]:
    print("great! Your code works for these inputs!")
else:
    print("something is off, your code produced the following:")
    print(path)


# ### 测试你的代码
# 如果下面的代码没有产生错误，那么你的算法的运行就是正确的。你马上就要提交项目了！在提交之前，请阅读以下提交清单：
# 
# **提交清单**
# 
# 1. 我的代码是否通过了所有测试？
# 2. 我的代码是否实现了`A*`搜索，而不是其他搜索算法？
# 3. 我是否使用**可接受的启发式程序**来实现搜索目标？
# 4. 我使用的数据结构是否可以避免不必要的慢速查找？
# 
# 当你对所有这些问题的回答都是“是的”时，请按下右下方的提交按钮进行提交！

# In[ ]:


from test import test

test(shortest_path)


# In[ ]:




