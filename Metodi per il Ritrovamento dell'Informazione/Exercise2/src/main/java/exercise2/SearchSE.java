package exercise2;

import org.apache.lucene.analysis.standard.StandardAnalyzer;
import org.apache.lucene.index.DirectoryReader;
import org.apache.lucene.queryparser.classic.QueryParser;
import org.apache.lucene.search.IndexSearcher;
import org.apache.lucene.search.Query;
import org.apache.lucene.search.ScoreDoc;
import org.apache.lucene.search.TopDocs;
import org.apache.lucene.store.FSDirectory;

import java.io.File;

public class SearchSE {
    public static void main(String[] args) {
        try {
            if (args.length == 2) {
                FSDirectory fsDirectory = FSDirectory.open(new File(args[0]).toPath());
                IndexSearcher indexSearcher = new IndexSearcher(DirectoryReader.open(fsDirectory));
                QueryParser queryParser = new QueryParser("text", new StandardAnalyzer());

                Query query = queryParser.parse(args[1]);
                TopDocs topDocs = indexSearcher.search(query, 10);
                for (ScoreDoc scoreDoc : topDocs.scoreDocs) {
                    System.out.println("Found doc\tPath: " + indexSearcher.doc(scoreDoc.doc).get("id") + "\tScore: " +
                            scoreDoc.score);
                }

            } else {
                throw new IllegalArgumentException("There must be two arguments:\n\t1: The first argument must be the " +
                        "path of the index\n\t2: The second argument must be the query");
            }
        } catch (Exception e) {
            System.err.println(e.getLocalizedMessage());
        }
    }
}
