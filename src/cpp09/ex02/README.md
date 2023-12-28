# Proper implementation of Ford-Johnson minimal comparision sorting algorithm

```c
[12, 3, 2, 9, 5, 8, 6, 11, 7, 4, 1, 10, 0]

    1a. Group elements into pairs
    [(12, 3), (2, 9), (5, 8), (6, 11), (7, 4), (1, 10)]             leftover: 0
    1b. Sort inside pairs according to the maximum value
    [(12, 3), (9, 2), (8, 5), (11, 6), (7, 4), (10, 1)]             leftover: 0
    1c. Sort the pairs recursively
        2a. Group elements into pairs
        [((12, 3), (9, 2)), ((8, 5), (11, 6)), ((7, 4), (10, 1))]   leftover: nothing
        2b. Sort inside pairs according to the maximum value
        [((12, 3), (9, 2)), ((11, 6), (8, 5)), ((10, 1), (7, 4))]   leftover: nothing
        2c. Sort the pairs recursively
            3a. Group elements into pairs
            [(((12, 3), (9, 2)), ((11, 6), (8, 5)))]                leftover: ((10, 1), (7, 4))
            3b. Sort inside pairs according to the maximum value
            [(((12, 3), (9, 2)), ((11, 6), (8, 5)))]                leftover: ((10, 1), (7, 4))
            3c. Sort the pairs recursively
                4. Array size is 1 so return the same array to the caller

            3d. Ungroup the pairs by putting them in main and pend chain
            [(((12, 3), (9, 2)), ((11, 6), (8, 5)))]                leftover: ((10, 1), (7, 4))
            main: [((11, 6), (8, 5))]                    # put the 1st minimum to main
            pend: []

            main: [((11, 6), (8, 5)), ((12, 3), (9, 2))] # put the 1st maximum to main
            pend: [((11, 6), (8, 5))]                    # put the 1st minimum to pend

            3e. Append leftover to pend
            main: [((11, 6), (8, 5)), ((12, 3), (9, 2))]
            pend: [((11, 6), (8, 5)), ((10, 1), (7, 4))] # Append leftover to pend

            3f. binary search insertion

            main: [((10, 1), (7, 4)), ((11, 6), (8, 5)), ((12, 3), (9, 2))]
            pend: [((11, 6), (8, 5)), ((10, 1), (7, 4))]
            return the main chain to the caller

        2d. Ungroup the pairs by putting them in main and pend chain
        [((10, 1), (7, 4)), ((11, 6), (8, 5)), ((12, 3), (9, 2))]    leftover: nothing
        main: [(7, 4)]                                    # put the 1st minimum to main
        pend: []

        main: [(7, 4), (10, 1)]                           # put the 1st maximum to main
        pend: [(7, 4)]                                    # put the 1st minimum to pend

        main: [(7, 4), (10, 1), (11, 6)]                  # put the 2nd maximum to main
        pend: [(7, 4), (8, 5)]                            # put the 2nd minimum to pend

        main: [(7, 4), (10, 1), (11, 6), (12, 3)]         # put the 3rd maximum to main
        pend: [(7, 4), (8, 5), (9, 2)]                    # put the 3rd minimum to pend

        2e. Append leftover to pend
        # no leftover elements to append to pend

        2f. binary search insertion

        main: [(7, 4), (8, 5), (9, 2), (10, 1), (11, 6), (12, 3)]
        pend: [(7, 4), (8, 5), (9, 2)]
        return the main chain to the caller

    1d. Ungroup the pairs by putting them in main and pend chain
    [(7, 4), (8, 5), (9, 2), (10, 1), (11, 6), (12, 3)]             leftover: 0
    main: [4]                                               # put the 1st minimum to main
    pend: []

    main: [4, 7]                                            # put the 1st maximum to main
    pend: [4]                                               # put the 1st minimum to pend

    main: [4, 7, 8]                                         # put the 2nd maximum to main
    pend: [4, 5]                                            # put the 2nd minimum to pend

    main: [4, 7, 8, 9]                                      # put the 3rd maximum to main
    pend: [4, 5, 2]                                         # put the 3rd minimum to pend

    main: [4, 7, 8, 9, 10]                                  # put the 4th maximum to main
    pend: [4, 5, 2, 1]                                      # put the 4th minimum to pend

    main: [4, 7, 8, 9, 10, 11]                              # put the 5th maximum to main
    pend: [4, 5, 2, 1, 6]                                   # put the 5th minimum to pend

    main: [4, 7, 8, 9, 10, 11, 12]                          # put the 6th maximum to main
    pend: [4, 5, 2, 1, 6, 3]                                # put the 6th minimum to pend

    1e. Append leftover to pend
    main: [4, 7, 8, 9, 10, 11, 12]
    pend: [4, 5, 2, 1, 6, 3, 0]                             # Append leftover to pend

    1f. binary search insertion

    main: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
    pend: [0, 1, 2, 3, 4, 5, 6]
    return the main chain to the caller

[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]

```