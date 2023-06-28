#define _USE_MATH_DEFINES
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

class Rectangle;

class Point {
public:
    Rectangle* rect;
    int x, y;
    double angle;
    char vertex;
};

class Rectangle {
public:
    int index;
    Point* a, * b, * c, * d;
    bool active;
    double distance;
};

double angle(int x, int y) {
    double angl = atan2(y, x);
    if (angl < 0) {
        angl += 2 * M_PI;
    }
    return angl;
}

double dist(const Rectangle& rect) {
    double x = (rect.a->x + rect.c->x) / 2.0;
    double y = (rect.a->y + rect.c->y) / 2.0;
    return hypot(x, y);
}

class Dist_Comparison {
public:
    bool operator()(const Rectangle* const& r1, const Rectangle* const& r2) const {
        return r1->distance < r2->distance;
    }
};

Point* nearest_pt(Rectangle rect) {
    if (rect.a->x >= 0 && rect.a->y <= 0 && rect.d->y >= 0) {
        return rect.d;
    }
    Point* MaxPoint = rect.d;
    Point* points[] = { rect.c, rect.b, rect.a };
    for (auto& point : points) {
        if (point->angle > MaxPoint->angle) {
            MaxPoint = point;
        }
    }
    return MaxPoint;
}

int main() {
    ifstream fin("input.txt");
    fstream fout("output.txt");
    int n; fin >> n;

    vector<Rectangle> rects(n);
    vector<Point*> pts;

    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        fin >> a >> b >> c >> d;
        rects[i].index = i;

        rects[i].a = new Point{ &rects[i], a, c, angle(a, c), 'a' };
        rects[i].b = new Point{ &rects[i], b, c, angle(b, c), 'b' };
        rects[i].c = new Point{ &rects[i], b, d, angle(b, d), 'c' };
        rects[i].d = new Point{ &rects[i], a, d, angle(a, d), 'd' };

        for (auto& point : { rects[i].a, rects[i].b, rects[i].c, rects[i].d }) {
            pts.emplace_back(point);
        }

        rects[i].distance = dist(rects[i]);
    }

    sort(pts.begin(), pts.end(), [](const Point* a, const Point* b) {
        if (a->angle == b->angle) {

            if (a->rect == b->rect) return a->vertex < b->vertex;

            else return a->rect->distance < b->rect->distance;
        }
        return a->angle < b->angle;
        });

    set<Rectangle*, Dist_Comparison> setik;
    set<int> indexes;

    for (int i = 0; i < n; i++) {
        if (rects[i].a->x >= 0 and rects[i].a->y <= 0 and rects[i].d->y >= 0) {
            rects[i].active = true;
            setik.insert(&rects[i]);
        }
    }

    if (!setik.empty()) {
        indexes.insert((*setik.begin())->index);
    }

    Point* prev_pt = nullptr;
    for (auto p : pts) {

        Rectangle* rect = p->rect;
        int prev_ind = (setik.empty() ? -1 : (*setik.begin())->index);

        if (not rect->active) {
            rect->active = true;
            setik.insert(rect);
        }

        else if (p == nearest_pt(*rect)) {
            rect->active = false;
            setik.erase(rect);
            prev_pt = p;
        }

        if (!setik.empty() and (*setik.begin())->index != prev_ind) {

            if (!prev_pt) {
                indexes.insert((*setik.begin())->index);
            }

            else if (nearest_pt(*(*setik.begin()))->angle != prev_pt->angle) {
                indexes.insert((*setik.begin())->index);
            }
        }
    }
    for (auto index : indexes) fout << index << endl;
}
