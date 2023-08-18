# GOAP_Research
My research for gameplay programming (Goal Oriented Action Planning)

Goal-Oriented-Action-Planning or GOAP is a program which like Finite-State-Machines and Behaviour-Trees tells an AI character what to do: run to point A, Shoot enemy... .

For the developer the biggest difference for GOAP is that is it much easier to add, remove or change actions. Since actions are independant from each other there is
no need to "go over all connections" like with FSM to check whether everything still flows correctly. (states have transitions that could break, actions do not).

For the player the biggest difference GOAP could make is a much more "intelligent" CPU opponent that makes more logical decisions.


GOAP is about is giving the AI a 'Goal or Purpose' & 'Actions' which it can perform. Action can have 'Preconditions' and will always have atleast 1 'Consequence'.
The AI creates a path of actions to satisfy its goal. This path is created by looking at the actions consequences and preconditions. Making sure each action
can be performed by finding another action that satisfies its precondition. (last actions consequence == goal)

EG) AI needs to kill enemy (Goal). It can use Shoot for this since it has consequence 'EnemyDies' (action). But this action requires his gun to
be loaded (precondition). Assuming the enemy is already in sight the actionPath becomes: ReloadGun() -> Shoot()


The main idea of GOAP is simple. The biggest problem for implementation is how do we define these "Goals, Preconditions and Consequences" that give meaning to actions.

My current idea is to use one huge enumeration in which each consequence is written. These would also be used as "Goals" and as "Preconditions" since that is actually "the same". (a goal or precondition can be viewed as another actions consequence)
Allowing "Goals, Preconditions and Consequences" to be from the same enumeration makes the code already easier. But there still remains a question in my head: what if a consequence requires more context?
