# CS 230 Operating Platforms: The Gaming Room Software Design Document

This repository holds the completed software design document I put together for The Gaming Room in CS 230. 
The file is `CS230Project3_BWILLIS_FINALCOPY.docx`. It builds on itself across the course: the Executive Summary, 
Requirements, Design Constraints, and Domain Model came first, then the platform Evaluation, and finally the Recommendations 
section covering the operating platform, architecture, storage, memory, distributed systems, and security.

## Who was the client and what did they want?

The client was The Gaming Room, a company that already had an Android-only game called Draw It or Lose It. They wanted to expand 
it into a web-based version that works across multiple platforms and devices instead of being stuck on one. The game has teams, 
and each team has players, so the software had to manage games, teams, and players while making sure only one instance of the game service
exists in memory at a time and that game and team names are unique. My job was to design that application and then recommend what it should run on.

## What did I do particularly well?

I think the strongest part was tying every design choice back to something the client actually asked for. The singleton for GameService and 
the iterator for the name checks both trace straight to the requirements instead of being patterns I added just because they were in the textbook. 
I also did well on the Recommendations section, where I tried to be specific. Instead of just saying "use the cloud," I worked out things like the
image library coming to about 1.6 GB (200 images at around 8 MB each), which is why I put it in object storage and kept the player and game records
in a database.

## What about working through a design document helped when developing the code?

Having the structure on paper first made the code go a lot faster. Once I had the UML diagram with Entity at the top and Game, Team, and Player 
inheriting from it, writing the Java was mostly filling in what I had already decided. It also caught problems early. Drawing the 0..* relationships 
made it obvious where the name checks needed to happen before anything got added. I've built plenty of things by just starting to code, and I've paid
for it later, so this was a good habit to be forced into.

## What would I revise?

If I could pick one thing, it would be the Domain Model and Evaluation sections from the earlier projects. The Domain Model write-up says there are 
six classes but lists seven, and the Evaluation section still has leftover template instructions above the table. Neither one changes the design, but 
they make the document look less finished than it should. I would also go back and add a real System Architecture View. That section is just a note
right now, and the Recommendations section describes the load balancer, game servers, database, and storage, so a simple diagram of those pieces 
would pull it together.

## How did I interpret the user's needs?

The client's two big needs were reaching more platforms and handling more players, so I pushed those through the whole design. For platform reach,
I kept the design free of platform-specific code and recommended browser clients that talk to a REST API, so Windows, Mac, Linux, iOS, and Android 
players all use the same backend. For growth, I recommended Linux servers in the cloud that can scale up and down with the number of players. Considering
the user's needs matters because a design that is technically clean but solves the wrong problem is useless. The client is the one who has to live with 
it, so every decision needs to be something they can point to and say it matches what they asked for.

## How did I approach designing the software?

I started with the requirements and worked outward: what the system has to do, what limits it, then how the classes relate, and only then which platform to put it on. For a similar application in the future, I would keep that order. I would also sketch the UML before touching code, pick patterns based on a specific requirement, and think about security and failure early instead of bolting them on. My time in the Navy working with systems where access is on a need-to-know basis shaped how I think about permissions and least privilege, and I would carry that into any design that handles user accounts or data. I would also compare cloud and serverless options sooner, since this last module showed me that event-driven pieces, like processing a finished game, can run without managing a server at all.
