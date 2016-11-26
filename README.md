# PlantsVsRabbits
This is a software design pattern class project, and its main content is a game like "Plants vs Zombies".

## 单例模式
将植物与兔子的管理者（RabbitManager, PlantManager）的使用由直接使用构造函数改为单例模式。

## 观察者模式
之前游戏中植物种植按钮始终为同一种状态，无论当前雨滴数目是否足够种植这种植物，玩家只有在点击按钮并种植到对应位置时才能发现有足够的雨滴来种植这种植物。  
经过修改后，我们为植物按钮添加了一种状态（灰色），表示当前这种植物还没有足够的阳光种植。  
![](resource_of_readme_file/observer_pattern_old.png)  
![](resource_of_readme_file/observer_pattern_new.png)  
考虑到只有在雨滴数目发生变化时，植物按钮的状态才会发生改变，因此我们选择在每一帧进行判断，将这一帧的雨滴数目与上一帧进行比较，仅在数目发生变化时才对按钮状态（可点击/不可点击）进行判断刷新
。

## 命令模式
种植植物时，原来的做法是将鼠标点击事件的监听、解析与种植动作在一起实现，耦合性过高，不利于实现 Redo/Undo 机制；将其改为监听者承担监听与解析任务，之后由监听者调用种植函数，实现命令模式。
