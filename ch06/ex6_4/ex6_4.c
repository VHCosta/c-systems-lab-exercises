/* ex6_4.c — X-macro state machine
 * gcc -Wall -Wextra -Werror -std=c11 -g -o ex6_4 ex6_4.c && ./ex6_4
 *
 * To add a new state: add one X() line to STATE_LIST.
 * The enum, string table, and STATE_COUNT all update automatically.
 */
#include <stdio.h>
#include <assert.h>

/* ── Single source of truth ── */
#define STATE_LIST          \
    X(IDLE,    "idle")      \
    X(RUNNING, "running")   \
    X(PAUSED,  "paused")    \
    X(DONE,    "done")      \
    X(ERROR,   "error")

#define EVENT_LIST          \
    E(START,   "start")     \
    E(PAUSE,   "pause")     \
    E(RESUME,  "resume")    \
    E(STOP,    "stop")

/* ── Expansion 1: enums ── */
typedef enum {
#define X(name, str) STATE_ ## name,
    STATE_LIST
#undef X
    STATE_COUNT
} state_t;

typedef enum {
#define E(name, str) EVENT_ ## name,
    EVENT_LIST
#undef E
    EVENT_COUNT
} event_t;

/* ── Expansion 2: string tables ── */
static const char *state_strings[STATE_COUNT] = {
#define X(name, str) [STATE_ ## name] = str,
    STATE_LIST
#undef X
};

static const char *event_strings[EVENT_COUNT] = {
#define E(name, str) [EVENT_ ## name] = str,
    EVENT_LIST
#undef E
};

const char *state_name(state_t s) {
    /* TODO: implement */
}

const char *event_name(event_t e) {
    /* TODO: implement */
}

/* ── Transition table ── */
static const state_t transitions[STATE_COUNT][EVENT_COUNT] = {
    /*                  START          PAUSE          RESUME         STOP       */
    [STATE_IDLE]    = { STATE_RUNNING, STATE_ERROR,   STATE_ERROR,   STATE_DONE  },
    [STATE_RUNNING] = { STATE_ERROR,   STATE_PAUSED,  STATE_ERROR,   STATE_DONE  },
    [STATE_PAUSED]  = { STATE_ERROR,   STATE_ERROR,   STATE_RUNNING, STATE_DONE  },
    [STATE_DONE]    = { STATE_ERROR,   STATE_ERROR,   STATE_ERROR,   STATE_ERROR },
    [STATE_ERROR]   = { STATE_ERROR,   STATE_ERROR,   STATE_ERROR,   STATE_ERROR },
};

state_t apply_event(state_t s, event_t e) {
    /* TODO: implement */
}

int main(void) {
    /* Print all states — automatically includes any newly added states */
    printf("States (%d total):\n", STATE_COUNT);
    for (int i = 0; i < STATE_COUNT; i++)
        printf("  %d: %s\n", i, state_name((state_t)i));

    /* Simulate a run */
    printf("\nSimulation:\n");
    state_t s = STATE_IDLE;
    event_t seq[] = { EVENT_START, EVENT_PAUSE, EVENT_RESUME, EVENT_STOP };
    for (int i = 0; i < 4; i++) {
        state_t next = apply_event(s, seq[i]);
        printf("  %-8s + %-6s  →  %s\n",
               state_name(s), event_name(seq[i]), state_name(next));
        s = next;
    }
    assert(s == STATE_DONE);

    /* Test invalid transition */
    state_t err = apply_event(STATE_DONE, EVENT_START);
    assert(err == STATE_ERROR);
    printf("\nInvalid: done + start → %s (correct)\n", state_name(err));

    printf("\nAll assertions passed — STATE_COUNT=%d\n", STATE_COUNT);
    return 0;
}
