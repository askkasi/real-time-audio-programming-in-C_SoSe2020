
# GIT COMMANDS 

## Initialize a local git and commit
New git

`$ mkdir MY_PROJECT && cd MY_PROJECT`

`$ git init`


Create a file.

`$ touch README.md`


Add file to index.

`$ git add README.md`


Add all (added/changed) files at ones to index.

`$ git add .`


Commit the added file(s) to the HEAD

`$ git commit -m "README added - first commit"`


## Connect your local git with a server
Connect local repo with server (remote git name must be same as local git name).

`$ git remote add origin <server_address>`


Change remote URL.

`$ git remote set-url origin <server_address>`

*Note: Repository names online and local must be the same*

Show your remote connection.

`$ git remote -v`



Till now, all is proceeded locally
Loading the files to the server to make them available for others.

`$ git push origin master`


When you are beginning your work, first make get a fresh copy

`$ git pull`


## Make a branch
Its good practice to have at least this minimal structure: MASTER <---> DEVELOPMENT <---> FEATURE

  * The master branch should always contain working minor versions
  * The development branch holds the working new features, that are not published or merged into the master branch
  * The feature branch(es) are holding separated features under development


``` shell
$ git branch DEVELOPMENT_BRANCH
$ git branch FEATURE_BRANCH
```


Show all branches.

`$ git branch -a -v`


Then make a branch to work with.

`$ git checkout -b WORKING_COPY`


Double check where you are.

`$ git status`


After your work all is fine and you want to merge into your `FEATURE_BRANCH`, first switch into your branch you wish to merge in.

`$ git checkout FEATURE_BRANCH`

`$ git merge WORKING_COPY`


First you could check if there are more branches that are not merged already.

`$ git branch --no-merged`


If you want, you can delete your WORKING_COPY.

`$ git branch -d WORKING_COPY`

Show changes.

`$ git diff FEATURE_BRANCH WORKING_COPY`

## Removing  uncommited changes
In the case, you try want to remove all untracked changes in your BRANCH.

`$ git checkout -- *`

Or just the changes in one file.

$ git checkout -- FILE_NAME

## Removing  commited changes
First view history and get the hash of your commit(s)

`$ git log`

`$ git log --stat`

or

`$ git log --pretty=oneline`

or

`$ git log --pretty=format:"%h - %an, %ar : %s"`

or with showing branches and merges in ASCII.

`$ git log --pretty=format:"%h %s" --graph`

`$ git log --pretty=format:"%h - %an, %ar : %s"  --graph`



### Filter in time
`$ git log --since=1.weeks`

`$ git log --since=2.days`

`$ git log --since=3.hours`

`$ git log --since=40.minutes`

`$ git log --pretty=format:"%h - %an, %ar : %s"  --graph --since=2.days`


### Show the last commit
`$ git rev-parse --short HEAD` or 

`$ git show -s --format=%h` or

`$ git describe --always` for showing short hash

`$ git rev-parse HEAD` or 

`$ git show -s --format=%H` for full hash


### You can make a own shortcut(s)
`$ git config --global alias.lastcommit "rev-parse HEAD`

`$ git lastcommit`

### Reset vs. revert
All later commit will be gone, you can just go back - history changed (private branch only).

`$ git reset HASH_OF_AN_EARLIER_COMMIT` 

You make a new commit with the content of the earlier commit, all commits in between stay saved (recommended) - history not changed (good practice on public branch).
`$ git revert HASH_OF_AN_EARLIER_COMMIT` 

### Now go back to an earlier commit
Choose your commit, copy the hash.

`$ git log --pretty=format:"%h - %an, %ar : %s"  --graph`


### Just switching without making any changes
`$ git checkout HASH_OF_COMMIT_TO_GO_BACK`


### Reset
`$ git checkout BRANCH`
`$ git reset HEAD~2`


### Stash
The phone rings in the middle of your work, and you have to do some fixes in another branch, but you are not ready to commit your work now

`$ git stash`

Now you want to turn back to your work

`$ git stash pop`


Show your stashes

`$ git stash list`


Show diffs of your stashes

`$ git stash show --patch`

Make a new branch from stash

`$ git stash branch NEW_BRANCH_NAME stash@{1}`

Clean

`$ git stash drop stash@{1}`

or remove all at ones

`$ git stash clear`


### Rebase
Situation: While you're working on your feature, the master is updated by someone else.
Now you want to integrate the new master updates into your feature branch.
With `rebase` you can move branches and merge them in one step into a new base to make the history linear again. 

*Note: This will change the history and should only done on your local branch*

`$ git rebase <base>`


If you running in conflicts, use 

`git mergetool` to fix them




to be continued...


















