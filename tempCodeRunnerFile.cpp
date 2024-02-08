
        HT[i] = NULL;
    
    InsertinHT(HT,12);
    InsertinHT(HT,22);  
    InsertinHT(HT,42);
   
    m = Search(HT[hash(22)], 22);

    if (m != NULL) {
        printf("%d\t", m->data);
    } else {
        printf("Key not found\n");
    }

    printf("Hello world\n");

    return 0;
}
