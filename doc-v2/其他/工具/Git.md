---
title: "Git"
date: 2022-08-11 
tags: [Git]
categories: [其他, 工具]
cover: false
---

### Git是什么？

Git是一个免费且开源的分布式版本控制系统。

### SVN和Git区别

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/git/wpsSGyorp.png)

### Git理论基础

将文件保存到Git时，所有数据都要进行内容的校验和（checksum）计算，并将此结果作为数据的唯一标识和索引。Git使用SHA-1算法计算数据的校验和，通过对文件的内容或目录的结构计算出一个SHA-1哈希值，作为指纹字符串。该字符串由40个十六进制字符组成，所有保存在Git数据库中的内容都是用此哈希值来做索引的，而不是靠文件名。

在Git中，文件有三种状态：

1. 已提交（committed）：表示该文件被保存到本地仓库，例如使用commit后的状态。

2. 已修改（modified）：表示本地仓库中的文件被修改了，但还没有提交保存，例如已经被Git管理的文件被修改，但未使用add操作或commit操作时的状态。

3. 已暂存（staged）：表示把已修改的文件放到下次提交时要保存的清单中，例如使用add操作将文件添加到暂存区，等待使用commit操作提交保存到本地仓库中。

Git中的三个工作区域：

1. 工作目录：本地实际操作的目录空间。

2. 暂存区：新修改或新添加的文件暂时存储的空间，这个区域的文件等待被提交或保存到本地仓库。

3. 本地仓库：存储变更的记录及文件。

三个工作区域之间的转换关系：

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/git/wpsaDzqr9.png)

### Git分支

#### 切换分支

Git中分支，本质上仅仅是一个指向commit对象的可变指针。如图：

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/git/wps6QGX26.png)

Git中有一个HEAD指针，它总是指向当前所在的本地分支，Git中分支的切换就是移动HEAD指针，指向对应的分支，如图：

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/git/wpsm8ia1t.png)

### 分支合并

下图中master主干分支上有C0、C1、C2和C4四次提交，同时以C2位基线创建了iss53分支，并且在iss53分支上做了C3和C5两次提交。

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/git/wpsgUsE09.png)

此时如果直接把iss53分支合并到master主干分支，就会生成一个合并提交C6，并且此时master指向这个commit对象，这就是分支合并。

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/git/wpsFRJz6c.png)

### 远程仓库和远程分支

Git在本地仓库存储了所有的文件和操作记录，Git在本地的这些版本镜像和操作记录，如果没有push，最终也只是保存到了本地仓库中，push必须要在远程Git服务器上有一个对应的远程仓库，这个远程仓库的结构和你本地仓库是一样的，这样其他人就可以通过这个远程仓库下载你在本地操作的变更了，Git默认的远程仓库名称是origin。

本地分支如果想推送到远程Git服务器，必须要在远程Git服务器上有一个相应的远程分支接应，这样远程分支就包含了本地分支推送的内容。

### Git常规使用

#### 查看帮助信息

```
git help
git --help
man git
```

#### 配置用户名和用户邮箱

```
git config --global user.name xiaoshan
git config --global user.email 975304386@qq.com
```

#### 下载远程仓库目录至本地

`git clone git@xxx.xxx.xxx:user/demo.git`

#### 查看文件变更的状态

`git status`

该命令会显示有没有变更，哪些文件变更了，处在什么状态，同时有相应的操作提示。

#### 将文件的内容添加到暂存区

```
git add file_name       #将指定文件的变更添加

git add file1_name file2_name #将指定文件的变更添加

git add *.php         #使用通配符将符合规则的文件变更添加

git add .           #添加当前目录及子目录下的所有变更

git add --all         #添加所有的变更

git add -A           #添加所有的变更
```

#### 查看文件之间的变更差异

```
git diff       #查看未暂存和已提交快照之间的差异

git diff --staged  #查看已暂存和已提交快照之间的差异

git diff HEAD    #查看工作区和当前分支最新commit之间的差异

git diff commitid  #工作区和历史版本之间的差异 or 当前分支最新版本和其他分支历      史版本之间的差异

git diff commitid1 commitid2 #两个历史版本之间的差异(第一个ID为参照) or 当前分支历史版本和其他分支历史版本之间的差异

git diff 分支名    #当前分支最新版本与其他分支最新版本之间的差异
```

#### 将文件的变更提交至本地仓库

```
git commit [file1] [file2] ... -m [message]

git commit -a -m "xxx"      #跳过暂存区直接commit，xxx标注    提交的注释

git commit --amend -m [message] #使用一次新的commit，替代上一次提交，如果代码没有任何新变化，则用来改写上一次commit的提交信息
```

#### 将本地仓库的变更推送到远程仓库

```
git push <远程仓库名> <本地分支名> <远程分支名>

git push origin develop:dev #将develop分支推送到远程origin仓库的dev分支

git push origin develop #将develop分支推送到远程origin仓库的develop分支

git push origin :dev #删除指定的远程分支

git push origin #将当前分支推送到远程origin仓库的对应分支

git push #当前分支只有一个远程分支，主机名都可以省略
```

#### 拉取远程仓库的变更到本地（不主动合并）

```
git fetch #当前分支只有一个远程分支，主机名都可以省略

git fetch <远程仓库名> #将某个远程仓库的更新全部取回本地

git fetch <远程仓库名> <分支名> #将某个远程仓库的某个分支的更新取回本地
```

#### 分支合并

`git merge <分支名> #将某个分支上的代码合并到当前分支`

拉取远程仓库的变更到本地（主动合并）

`git pull [remote] [branch] #remote为远程仓库，branch为远程分支，这两个参数都可以省略，省略则默认拉取已经追踪的远程仓库的远程分支的文件`

#### 丢弃未加入到缓存区的修改

```
git checkout -- filename #丢弃某个文件的变更

git ckeckout filename #丢弃某个文件的变更

git ckeckout . #丢弃所有文件的变更
```

#### 切换分支

```
git ckeckout <分支名>

git checkout -b <新分支名> #如果分支不存在则新建
```

#### 删除Git中内容

```
git rm xxx #从已跟踪文件清单中移除，会删除文件

git rm -f xxx #强制删除已暂存中的修改

git rm --cache xxx #删除暂存区中的修改(不再追踪)，不删除文件，且保留变更

git rm log/\*.log #删除log目录下.log的文件
```

#### 撤销操作

- 未add撤销

`git checkout xxx`

- add后，未commit撤销

```
git reset HEAD xxx #撤销指定文件修改

git reset HEAD . #撤销当前所有修改
```

- commit后撤销

```
git reset --soft HEAD^ #撤销commit回到前一个版本，不撤销git add，不恢复变更

git reset --soft HEAD~1 #撤销commit回到前一个版本，不撤销git add，不恢复变更

git reset --soft HEAD~2 #撤销commit回到前两个版本，不撤销git add，不恢复变更

git reset --mixed HEAD^ #撤销commit回到前一个版本，并撤销git add，不恢复变更

git reset --hard HEAD^  #撤销commit回到前一个版本，撤销git add，恢复变更
```

- 恢复到某一次提交

`git reset --hard commitid`

#### 查看提交历史

`git log`

#### 变更隐藏和恢复

```
git stash save "save message" #将变更暂时存储并隐藏，不包含未被追踪的文件

git stash list #stash列表

git stash show #显示做了哪些改动，默认show第一个存储,如果要显示其他存储，后面加stash@{$num}，比如第二个 git stash show stash@{1}

git stash show -p #

git stash show -p 显示第一个存储的改动，如果想显示其他存存储使用git stash show  stash@{$num}  -p ，比如第二个：git stash show  stash@{1}  -p

git stash apply #恢复某个存储,但不会把存储从存储列表中删除，默认使用第一个存储,即stash@{0}，如果要恢复其它，git stash apply stash@{$num} ，比如第二个：git stash apply stash@{1}

git stash pop #恢复之前存储的变更，将缓存堆栈中的对应stash删除，并将对应修改应用到当前的工作目录下,默认为第一个stash,即stash@{0}，如果要应用并删除其他stash，使用git stash pop stash@{$num} ，比如应用并删除第二个：git stash pop stash@{1}

git stash drop stash@{$num} #丢弃stash@{$num}存储，从列表中删除这个存储

git stash clear #删除所有缓存的stash

git stash push -u #将变更暂时存储并隐藏，包含未被追踪的文件

git stash push -a #被修改的文件连同被忽略文件也被存储起来
```

#### 常规操作图示

![img](https://raw.githubusercontent.com/shershon1991/picImgBed/master/git/wpscBqsO0.png) 

 

 