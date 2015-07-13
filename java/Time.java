import java.util.Calendar;

class Time {
    public static void main(String[] args) {

        Calendar now = Calendar.getInstance();

        int hour = now.get(Calendar.HOUR_OF_DAY);
        int min = now.get(Calendar.MINUTE);
        int secs = now.get(Calendar.SECOND);

        float secondsSinceMidnight = hour*3600 + min*60 + secs;
        float secondsUntilMidnight = 24*3600 - secondsSinceMidnight;
        float percentOfDayPassed = ((secondsSinceMidnight/3600)/24) * 100;

        String formattedPercent = String.format("%.02f", percentOfDayPassed);

        System.out.println("Seconds since midnight: " + secondsSinceMidnight);
        System.out.println("Seconds until midnight: " + secondsUntilMidnight );
        System.out.println("Percentage of day passed: " + formattedPercent + "%");


    }
}
