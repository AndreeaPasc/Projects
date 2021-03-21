-----------------------
-- Pașc Andreea-Mădălina
-- 12.10.2020
-----------------------
-- Edit the lines above with your name and the submission date.

module Solutions exposing (..)

--import Solutions exposing (..)

-------------------- 1.2.1 --------------------
type Face = Ace|Two|Three|Four|Five|Six|Seven|Eight|Nine|Ten|Jack|Queen|King
type Suit = Clubs|Diamonds|Hearts|Spades
type Card = Card Face Suit
-----------------------------------------------

-------------------- 1.2.2 --------------------
faceToString : Face -> String
faceToString face =
    case face of
    Ace -> "Ace"
    Two -> "Two"
    Three -> "Three"
    Four -> "Four"
    Five -> "Five"
    Six -> "Six"
    Seven -> "Seven"
    Eight -> "Eight"
    Nine -> "Nine"
    Ten -> "Ten"
    Jack -> "Jack"
    Queen -> "Queen"
    King -> "King"

suitToString : Suit -> String
suitToString suit =
    case suit of
        Clubs -> "Clubs"
        Diamonds -> "Diamonds"
        Hearts -> "Hearts"
        Spades -> "Spades"

cardToString : Card -> String
cardToString card =
    let
        (Card face suit) = card
    in
        faceToString face ++ " of " ++ suitToString suit
-----------------------------------------------

-------------------- 1.2.3 --------------------
type alias Point = {x: Float, y: Float}
type Segment = Segment Point Point


-- s1(x1, y1) e1(x1, y1) s2(x2, y2) e2(x2, y2)
-- start.x < end.x

linesIntersect segment1 segment2 =
    let
        (Segment s1 e1) = segment1
        (Segment s2 e2) = segment2

        slope start end = (end.y - start.y) / (end.x - start.x)

        intersectX s1_var e1_var s2_var e2_var =
            ((s1_var.x * e1_var.y - s1_var.y * e2_var.x) * (s2_var.x - e2_var.x) - (s1_var.x - e1_var.x) * (s2_var.x * e2_var.y - s2_var.y * e2_var.x)) /
            ((s1_var.x - e1_var.x) * (s2_var.y - e2_var.y) - (s1_var.y - e1_var.y) * (s2_var.x - e2_var.x))
        intersectY s1_var e1_var s2_var e2_var =
            ((s1_var.x * e1_var.y - s1_var.y * e1_var.x) * (s2_var.y - e2_var.y) - (s1_var.y - e1_var.y) * (s2_var.x * e2_var.y - s2_var.y * e2_var.x)) /
            ((s1_var.x - e1_var.x) * (s2_var.y - e2_var.y) - (s1_var.y - e1_var.y) * (s2_var.x - e2_var.x))
    in
        if (slope s1 e1) == (slope s2 e2) then False
            else
            let
                x = intersectX s1 e1 s2 e2
                y = intersectY s1 s2 e1 e2
            in
                if (x >= s1.x && x >= s2.x && x <= e1.x && x <= e2.x &&
                    y <= s1.y && y <= s2.y && y <= e1.y && y <= e2.y) then True else False
-----------------------------------------------

-------------------- 1.2.4 --------------------
-- acc = 1
trailingZeros n acc =
    let
        fiveFact n2 acc2 =
            if (modBy 5 n2) == 0 then fiveFact (round (toFloat n2 / 5)) (acc2 + 1) else acc2
    in
        if n == 0 then acc - 1 else trailingZeros (n - 1) (fiveFact n acc)
