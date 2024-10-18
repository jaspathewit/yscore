# yScore

A personal score board for badminton based on the [Tinyscreen+](https://tinycircuits.com/products/tinyscreenplus).

The name, I have a habit of naming my projects with terrible puns. This one is no exception. The "y" in yScore is a play
on the word "why" as in "Why would you keep the score? I'll do it".

## Introduction

Lots of people when playing badminton (especially when they are beginners) find it difficult to know in which half of the
court they should stand, who will serve and what the current score is.

I had the idea of handing all that over to a simple "Wearable".

After talking about the idea with a friend (Johan Schokkaert) that also does a bit of Arduino development. He produced a bulky
prototype that could keep track of the score, essentially two counters increased by pressing two different buttons.

I then developed a second prototype based on adafruit feather zero and small LCD screen, which took things much further.
Fitting the rapidly expanding functionality into the limited memory available on Arduino feather was a challenge and
Making the case pushed my wood working abilities, such as they are, to their limit. The resulting device too big to be
worn on the wrist and ended up being worn on a belt during play.

This prototype proved that such a device was workable.

The third iteration of this idea was based on the Tinyscreen+ device. This powerful device opened up many possibilities
and these have been incorporated into the software. Importantly the device is small enough to be worn on the wrist.
Supports a small color screen and a powerful processor, importantly more memory and a battery that can easily be
recharged.

Highlights of the resulting application are:

+ Localised into 3 languages, English, Dutch and French
+ Can be converted for left-handed players
+ Supports different levels of screen brightness
+ Can keep track of the score (it records each point played in the game at it us possible to go back any number of points
to correct a mistake)
+ Implements the Badminton scoring system (over three sets) and will display the "winner" when the game is over
+ Summary screen that shows the current score and time played
+ Displays who will serve who will receive and where the players should be standing (it also shows if you should be happy because you
won the last point or sad because you lost it)
+ Handedness, screen brightness and language are persisted even after the device is turned off.
+ It has a constant operating time of about 24 hours on a single charge, and a standby time of around 20 days.

On the technical side. The application is written in C++ (makes use of three libraries) and implements a simple state
machine. There is clear separation between the Model, View and Controller. I also anti-aliased the fonts used to
improve the readability of the text on the small screen.

I was able to get members of a youth badminton club interested in the device and some provided feedback
that was incorporated into the final version of the software. (The handedness of the player and the brightness of the
screen). Ultimately, however the cost of the Tinyscreen+ device (Once EU tax has been applied on the import, together
with the difficulty of sourcing the miniscule batteries) made the device too expensive for the club to
consider. The idea of a member borrowing a device and then returning it was rejected as it was felt that too many would
end up being lost or damaged.

## Build

These instructions need some work (I'll update them when I find the time).

Using vscode, configure the development environment, following this [guide](https://learn.tinycircuits.com/Processors/TinyScreen+_Setup_Tutorial/)

Clone this repository and open it with vscode.

Build and upload to the Tinyscreen+ device

## Contributors

Special thanks goes to Johan Schokkaert who pushed me on to "finish" the code (even when it became apparent that the 
device was going to end up way too expensive. He also modified and finalised the 3D print design for the case.

## Contribute

In the unlikely event that anyone was interested in contributing... I'm open to pull requests.

## Finally

I've sometimes thought of porting this to the TTGO T-Watch-2020 V3, as the hardware provides many more possibilities,
especially with respect to networking and overall the device is cheaper than the Tinyscreen+. Maybe some day.
