#ifdef AMQ2
 if (wl == "amq2_1_1")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_1_1_1>());
 else if (wl == "amq2_1_0.95")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_1_95_100>());
 else if (wl == "amq2_1_0.9")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_1_9_10>());
 else if (wl == "amq2_1_0.5")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_1_5_10>());
 else if (wl == "amq2_1_0.1")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_1_1_10>());
 else if (wl == "amq2_1_0.05")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_1_5_100>());
 else if (wl == "amq2_1_0.03")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_1_3_100>());
 else if (wl == "amq2_1_0.01")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_1_1_100>());
 else if (wl == "amq2_1_0.005")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_1_5_1000>());
 else if (wl == "amq2_1_0.001")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_1_1_1000>());
 else if (wl == "amq2_0.95_1")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_95_100_1_1>());
 else if (wl == "amq2_0.95_0.95")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_95_100_95_100>());
 else if (wl == "amq2_0.95_0.9")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_95_100_9_10>());
 else if (wl == "amq2_0.95_0.5")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_95_100_5_10>());
 else if (wl == "amq2_0.95_0.1")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_95_100_1_10>());
 else if (wl == "amq2_0.95_0.05")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_95_100_5_100>());
 else if (wl == "amq2_0.95_0.03")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_95_100_3_100>());
 else if (wl == "amq2_0.95_0.01")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_95_100_1_100>());
 else if (wl == "amq2_0.95_0.005")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_95_100_5_1000>());
 else if (wl == "amq2_0.95_0.001")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_95_100_1_1000>());
 else if (wl == "amq2_0.9_1")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_9_10_1_1>());
 else if (wl == "amq2_0.9_0.95")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_9_10_95_100>());
 else if (wl == "amq2_0.9_0.9")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_9_10_9_10>());
 else if (wl == "amq2_0.9_0.5")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_9_10_5_10>());
 else if (wl == "amq2_0.9_0.1")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_9_10_1_10>());
 else if (wl == "amq2_0.9_0.05")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_9_10_5_100>());
 else if (wl == "amq2_0.9_0.03")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_9_10_3_100>());
 else if (wl == "amq2_0.9_0.01")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_9_10_1_100>());
 else if (wl == "amq2_0.9_0.005")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_9_10_5_1000>());
 else if (wl == "amq2_0.9_0.001")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_9_10_1_1000>());
 else if (wl == "amq2_0.5_1")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_10_1_1>());
 else if (wl == "amq2_0.5_0.95")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_10_95_100>());
 else if (wl == "amq2_0.5_0.9")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_10_9_10>());
 else if (wl == "amq2_0.5_0.5")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_10_5_10>());
 else if (wl == "amq2_0.5_0.1")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_10_1_10>());
 else if (wl == "amq2_0.5_0.05")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_10_5_100>());
 else if (wl == "amq2_0.5_0.03")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_10_3_100>());
 else if (wl == "amq2_0.5_0.01")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_10_1_100>());
 else if (wl == "amq2_0.5_0.005")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_10_5_1000>());
 else if (wl == "amq2_0.5_0.001")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_10_1_1000>());
 else if (wl == "amq2_0.1_1")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_10_1_1>());
 else if (wl == "amq2_0.1_0.95")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_10_95_100>());
 else if (wl == "amq2_0.1_0.9")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_10_9_10>());
 else if (wl == "amq2_0.1_0.5")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_10_5_10>());
 else if (wl == "amq2_0.1_0.1")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_10_1_10>());
 else if (wl == "amq2_0.1_0.05")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_10_5_100>());
 else if (wl == "amq2_0.1_0.03")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_10_3_100>());
 else if (wl == "amq2_0.1_0.01")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_10_1_100>());
 else if (wl == "amq2_0.1_0.005")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_10_5_1000>());
 else if (wl == "amq2_0.1_0.001")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_10_1_1000>());
 else if (wl == "amq2_0.05_1")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_100_1_1>());
 else if (wl == "amq2_0.05_0.95")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_100_95_100>());
 else if (wl == "amq2_0.05_0.9")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_100_9_10>());
 else if (wl == "amq2_0.05_0.5")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_100_5_10>());
 else if (wl == "amq2_0.05_0.1")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_100_1_10>());
 else if (wl == "amq2_0.05_0.05")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_100_5_100>());
 else if (wl == "amq2_0.05_0.03")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_100_3_100>());
 else if (wl == "amq2_0.05_0.01")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_100_1_100>());
 else if (wl == "amq2_0.05_0.005")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_100_5_1000>());
 else if (wl == "amq2_0.05_0.001")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_100_1_1000>());
 else if (wl == "amq2_0.03_1")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_3_100_1_1>());
 else if (wl == "amq2_0.03_0.95")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_3_100_95_100>());
 else if (wl == "amq2_0.03_0.9")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_3_100_9_10>());
 else if (wl == "amq2_0.03_0.5")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_3_100_5_10>());
 else if (wl == "amq2_0.03_0.1")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_3_100_1_10>());
 else if (wl == "amq2_0.03_0.05")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_3_100_5_100>());
 else if (wl == "amq2_0.03_0.03")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_3_100_3_100>());
 else if (wl == "amq2_0.03_0.01")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_3_100_1_100>());
 else if (wl == "amq2_0.03_0.005")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_3_100_5_1000>());
 else if (wl == "amq2_0.03_0.001")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_3_100_1_1000>());
 else if (wl == "amq2_0.01_1")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_100_1_1>());
 else if (wl == "amq2_0.01_0.95")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_100_95_100>());
 else if (wl == "amq2_0.01_0.9")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_100_9_10>());
 else if (wl == "amq2_0.01_0.5")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_100_5_10>());
 else if (wl == "amq2_0.01_0.1")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_100_1_10>());
 else if (wl == "amq2_0.01_0.05")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_100_5_100>());
 else if (wl == "amq2_0.01_0.03")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_100_3_100>());
 else if (wl == "amq2_0.01_0.01")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_100_1_100>());
 else if (wl == "amq2_0.01_0.005")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_100_5_1000>());
 else if (wl == "amq2_0.01_0.001")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_100_1_1000>());
 else if (wl == "amq2_0.005_1")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_1000_1_1>());
 else if (wl == "amq2_0.005_0.95")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_1000_95_100>());
 else if (wl == "amq2_0.005_0.9")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_1000_9_10>());
 else if (wl == "amq2_0.005_0.5")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_1000_5_10>());
 else if (wl == "amq2_0.005_0.1")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_1000_1_10>());
 else if (wl == "amq2_0.005_0.05")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_1000_5_100>());
 else if (wl == "amq2_0.005_0.03")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_1000_3_100>());
 else if (wl == "amq2_0.005_0.01")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_1000_1_100>());
 else if (wl == "amq2_0.005_0.005")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_1000_5_1000>());
 else if (wl == "amq2_0.005_0.001")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_5_1000_1_1000>());
 else if (wl == "amq2_0.001_1")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_1000_1_1>());
 else if (wl == "amq2_0.001_0.95")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_1000_95_100>());
 else if (wl == "amq2_0.001_0.9")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_1000_9_10>());
 else if (wl == "amq2_0.001_0.5")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_1000_5_10>());
 else if (wl == "amq2_0.001_0.1")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_1000_1_10>());
 else if (wl == "amq2_0.001_0.05")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_1000_5_100>());
 else if (wl == "amq2_0.001_0.03")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_1000_3_100>());
 else if (wl == "amq2_0.001_0.01")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_1000_1_100>());
 else if (wl == "amq2_0.001_0.005")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_1000_5_1000>());
 else if (wl == "amq2_0.001_0.001")
	    Galois::for_each(boost::make_transform_iterator(graph.begin(), std::ref(fn)),
                     boost::make_transform_iterator(graph.end(), std::ref(fn)),
                     Process(graph, tolerance, amp), Galois::wl<AMQ2_1_1000_1_1000>());
#endif
