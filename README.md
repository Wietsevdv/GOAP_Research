# GOAP_Research
My research for gameplay programming (Goal Oriented Action Planning)

Goal-Oriented-Action-Planning or GOAP is a program which like Finite-State-Machines and Behaviour-Trees tells an AI character what to do like: run to point A, Shoot enemy... .

For the developer the biggest difference for GOAP is that is it much easier to add, remove or change actions. Since actions are independant from each other there is
no need to "go over all connections" like with FSM to check whether everything still flows correctly.

For the player the biggest difference GOAP could make is a much more "intelligent" CPU opponent that makes more logical decisions.

# My approach to GOAP
My GOAP is about giving the AI a 'Goal or Purpose' and 'Actions' which it can perform. Action can have 'Preconditions' and will always have atleast 1 'Consequence'.
The AI creates a path of actions to satisfy its goal. This path is created by looking at the actions consequences and preconditions. Making sure each action
can be performed by finding other actions that satisfy its precondition. (last actions consequence == goal)

# Difficulties: Consequences, Purpose & context for actions/consequences
The main idea of GOAP is simple. The biggest problem for implementation is how do we define these "Goals, Preconditions and Consequences" that give meaning to actions.

### Consequences:
My current idea is to use one huge enumeration in which each consequence is written. These would also be used as "Goals" and as "Preconditions" since those are kind of the same. A goal or precondition can be viewed as an actions consequence.
Allowing "Goals, Preconditions and Consequences" to be from the same enumeration makes the code already easier. But there still remains a question in my head: what if a consequence requires more context?

### Purpose:
Another difficult part is what goal is the AI given? Does it just have 1 goal that it keeps trying to fulfill? What if it's goal is more complex? Like surviving, which would require it to check multiple things and choose a current consequence which needs to happen.
For this I was thinking to use a class called "Purpose" which could also be named "Brain" or "DecisionMaker". This class will check multiple stats on the character and depending on the current state decide a consequence to send to the GOAP to find an actionPath for.

### Context:
My main problem with using the 'Consequence' enumeration is that to make it work without anything else it would require an enormous enumeration. eg) Have10Coins, Have150Coins, Have1000Coins... You see where this is going. A solution could be a more general consequences enumeration and use them with context through a void pointer or template. eg) HaveCoins, Context = 100.  AimAtEnemy, Context = enemy5...
But I see another problem with this. I'll explain through example:

take character c1. c1 needs to chop a tree. This requires c1 to match consequence "ObtainAxe" Context = 1. This means GOAP needs to check this precondition on c1. GOAP would need to ask c1 if he has 1 axe. Code wise this requires some "GetNrOfAxes(), HasAxes(1)..." kind of function.

This becomes a problem when you have many consequences. Each consequence would need some code to get values & compare them. Though I can't think of a better solution right now so I'll be using this method.

## Trouble
Today I should finish this research. But I have come to realize that using static actions & purpose might not be good. I need to carry data over to both preconditions & actions to chain them execute them properly
### new base idea
I have a new base idea which I will be implementing. I am taking a "completely" other approach/perspective this time. The AI itself will be a class that contains a character and a GOAP (actions, preconditions, consequences, path of action creation). The AI class will than be responsible for checking the world and itself. And then choosing which action it wants to do. It then passes this action and extra data for context to the GOAP so it can create a path of action for the brain to follow. I will make the brain store the actionPath (vector reference to GOAP)

Brain will be capable of checkings stats and deciding what action it wants to do and asks GOAP to make a path. This means brain needs to be able to check preconditions. It would be handy if GOAP has access to the brains precondition checking function. Make the brain pass a function pointer to the GOAP at creation. This function takes a consequence (precondition) (and maybe data?)

During the GOAPs path creating it needs context for the preconditions. (ChopTree -> HaveAxe & need a tree -> what tree?) This question for context will be asked by goap, through the action to the brain. Checking preConditions for ChopTree: HaveAxe & HaveLocation -> GOAP makes the action ask the brain if it has an axe and where it should go (nearest tree or something)

A visual to hopefully explain the structure somewhat:
![info](https://github.com/Wietsevdv/GOAP_Research/assets/99739337/a011dbdb-6f69-472d-88ba-d6e60612fee6)

